#include<iostream>
using namespace std;
class Shape{
    public:
        virtual void draw(){
            cout<<"Drawing a Generic Shape";
        }
};
class Circle:public Shape{
    public:
        void draw(){
            cout<<"Drawing a Circle";
        }
};
class Rectangle:public Shape{
    public:
        void draw(){
            cout<<"Drawing a Rectangle";
        }
};
int main(){
    Shape *s;
    Circle c;
    Rectangle r;

    s=&c;
    s->draw();

    s=&r;
    s->draw();
    return 0;
}