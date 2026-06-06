import qrcode as qr 
#we can set nickname -> qrcode as  qr

#simple qr generator
img=qr.make(input(f'Enter the url or txt to make the qr code : '))
img.save("QRcode.png")