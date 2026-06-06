import sys

try:
    import qrcode
except ImportError:
    print("Error: Required libraries ('qrcode' or 'Pillow') are not installed.")
    print("Please run: pip install qrcode[pil] Pillow")
    sys.exit(1)

def create_qr():
    data = input('Enter the text or the URL: ').strip()
    if not data:
        print("Error: No data provided. Cannot generate an empty QR code.")
        return

    filename = input('Enter the file name (e.g., my_qr.png): ').strip()
    if not filename:
        filename = "my_qr_code.png"

    # Pillow requires a file extension to determine the image format
    if not filename.lower().endswith(('.png', '.jpg', '.jpeg')):
        filename += '.png'

    try:
        qr = qrcode.QRCode(box_size=10, border=6)
        qr.add_data(data)
        qr.make(fit=True)
        img = qr.make_image(fill_color='black', back_color='white')
        img.save(filename)
        print(f'Success! Your QR code has been saved as: {filename}')
    except Exception as e:
        print(f"An error occurred while saving the image: {e}")

if __name__ == "__main__":
    create_qr()