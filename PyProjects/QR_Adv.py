#Advanced qr generator
import qrcode
from PIL import Image
#PIL used in formating the image -> imorting the file Image

#to remove any overlapping errors 
qr=qrcode.QRCode(version=1,
                 error_correction=qrcode.constants.ERROR_CORRECT_H,
                 box_size=10,
                 border=4,)

qr.add_data(input("Enter the text or URL to attach : "))
qr.make(fit=True)#fit = True is used to check wheather the user has given any value or not
#if it finds data in add_data then only it will make the qrcode

#setting the user defined color
color1 = "black"
color2 = "white"
ch=input("Do you want to set your custom color? (y/n) : ").lower()
if(ch=='y'):
    color1=input("Enter the fill color : ")
    color2=input("Enter the back color : ")


img=qr.make_image(fill_color=color1, back_color=color2)

img.save("QRCode_Advanced.png")