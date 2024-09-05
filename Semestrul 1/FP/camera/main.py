import numpy as np
import cv2
from pyzbar.pyzbar import decode
from datetime import datetime

cap = cv2.VideoCapture(0)


def get_text_from_cod():
    ok = True
    while (ok == True):
        ret , img = cap.read()
        for barcode in decode(img):
            myData = barcode.data.decode('utf-8')
            if myData: # daca am gasit un bar code sau qr code

                return myData # returneaza textul obtinut din cod

        cv2.imshow('window' , img)

        if cv2.waitKey(1) == ord('q'):
            ok = False

def main():
    print(get_text_from_cod())

main()