import sqlite3
from flask import Flask, request, jsonify
from flask_cors import CORS
from werkzeug.security import generate_password_hash, check_password_hash
import jwt
from datetime import datetime, timedelta
from functools import wraps
import re
import os

app = Flask(__name__)
CORS(app)

# Database Setup
def init_db():
    conn = sqlite3.connect('mentor.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS users 
                 (id INTEGER PRIMARY KEY, name TEXT, email TEXT UNIQUE, password TEXT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP)''')
    conn.commit()
    conn.close()

init_db()

# JWT Config
app.config['SECRET_KEY'] = 'your-super-secret-jwt-key-change-in-production'
JWT_EXPIRY_HOURS = 1

def generate_token(user_id, email):
    payload = {
        'user_id': user_id,
        'email': email,
        'exp': datetime.utcnow() + timedelta(hours=JWT_EXPIRY_HOURS)
    }
    return jwt.encode(payload, app.config['SECRET_KEY'], algorithm='HS256')

def verify_token(token):
    try:
        payload = jwt.decode(token, app.config['SECRET_KEY'], algorithms=['HS256'])
        return payload
    except jwt.ExpiredSignatureError:
        return None
    except jwt.InvalidTokenError:
        return None

def token_required(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        token = request.headers.get('Authorization')
        if not token:
            return jsonify({'error': 'Token missing'}), 401
        token = token.split(' ')[1] if ' ' in token else token
        payload = verify_token(token)
        if not payload:
            return jsonify({'error': 'Invalid or expired token'}), 401
        current_user = payload
        return f(current_user, *args, **kwargs)
    return decorated

def validate_register_data(data):
    if not data or not isinstance(data, dict):
        return False, "Invalid JSON"
    if not data.get('fullName') or len(data['fullName'].strip()) < 2:
        return False, "Full name must be at least 2 chars"
    if not data.get('email') or not re.match(r'^[^@]+@[^@]+\.[^@]+$', data['email']):
        return False, "Valid email required"
    if not data.get('password') or len(data['password']) < 8:
        return False, "Password must be at least 8 chars"
    return True, ""

@app.route('/api/auth/register', methods=['POST'])
def register():
    data = request.json
    is_valid, error_msg = validate_register_data(data)
    if not is_valid:
        return jsonify({"error": error_msg}), 400

    hashed_password = generate_password_hash(data['password'])
    try:
        conn = sqlite3.connect('mentor.db')
        c = conn.cursor()
        c.execute("INSERT INTO users (name, email, password) VALUES (?, ?, ?)", 
                  (data['fullName'], data['email'], hashed_password))
        user_id = c.lastrowid
        conn.commit()
        token = generate_token(user_id, data['email'])
        return jsonify({"message": "User registered", "token": token, "name": data['fullName']}), 201
    except sqlite3.IntegrityError:
        return jsonify({"error": "Email already exists"}), 400
    except Exception as e:
        return jsonify({"error": "Registration failed"}), 500
    finally:
        conn.close()


@app.route('/api/auth/login', methods=['POST'])
def login():
    data = request.json
    if not data or not data.get('email') or not data.get('password'):
        return jsonify({"error": "Email and password required"}), 400

    conn = sqlite3.connect('mentor.db')
    c = conn.cursor()
    c.execute("SELECT id, name, email, password FROM users WHERE email = ?", (data['email'],))
    user = c.fetchone()
    conn.close()
    
    if user and check_password_hash(user[3], data['password']):
        token = generate_token(user[0], user[2])
        return jsonify({"name": user[1], "email": user[2], "token": token}), 200
    return jsonify({"error": "Invalid credentials"}), 401

@app.route('/api/profile', methods=['GET'])
@token_required
def profile(current_user):
    conn = sqlite3.connect('mentor.db')
    c = conn.cursor()
    c.execute("SELECT id, name, email, created_at FROM users WHERE email = ?", (current_user['email'],))
    user = c.fetchone()
    conn.close()
    if user:
        return jsonify({
            "id": user[0],
            "name": user[1],
            "email": user[2],
            "created_at": user[3]
        }), 200
    return jsonify({"error": "User not found"}), 404

if __name__ == '__main__':
    app.run(debug=True, port=5000)
