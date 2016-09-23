import serial
import time
from Tkinter import *
import tkMessageBox
root = Tk()
root.iconbitmap(default='Icon3.png.ico')
menu = Menu(root)
root.config(menu=menu)
root.geometry('450x550+400+200')
root.title('DMX Controller')


def about1():
    tkMessageBox.showinfo('About',
                          'Hello \nSoftware Version is 1.0  \nIf you have any questions please contact me at \n'
                          '111@111.com ')

subMenu = Menu(menu)
menu.add_cascade(label="File", menu=subMenu)

subMenu.add_command(label="Exit", command=menu.quit)

helpMenu = Menu(menu)
menu.add_cascade(label="Help", menu=helpMenu)
helpMenu.add_command(label="About" ,command=about1)


DMXOPEN = chr(126)
DMXCLOSE = chr(231)
DMXINTENSITY = chr(6) + chr(1) + chr(2)
DMXINIT1 = chr(03) + chr(02) + chr(0) + chr(0) + chr(0)
DMXINIT2 = chr(10) + chr(02) + chr(0) + chr(0) + chr(0)
ser = serial.Serial(0)
ser.write(DMXOPEN + DMXINIT1 + DMXCLOSE)
ser.write(DMXOPEN + DMXINIT2 + DMXCLOSE)
dmxdata = [chr(0)] * 513

def senddmx(data, chan, intensity):
    data[chan] = chr(intensity)
    sdata = ''.join(data)
    ser.write(DMXOPEN + DMXINTENSITY + sdata + DMXCLOSE)
    return (data)

Len=500
Wi=40
def CH1(self):
    d = scl.get()
    data = senddmx(dmxdata, 1, d)

def CH2(self):
    d = sc2.get()
    data = senddmx(dmxdata, 2, d)

def CH3(self):
    d = sc3.get()
    data = senddmx(dmxdata, 3, d)

def CH4(self):
    d = sc4.get()
    data = senddmx(dmxdata, 4, d)

scl = Scale(root, from_=255, to=0,  resolution=1,width=Wi,length=Len,label="Red",command=CH1)
scl.grid(row=0, column=0, )

sc2 = Scale(root, from_=255, to=0,  resolution=1,width=Wi,length=Len,label="Green",command=CH2)
sc2.grid(row=0, column=1, )

sc3 = Scale(root, from_=255, to=0,  resolution=1,width=Wi,length=Len,label="Blue",command=CH3)
sc3.grid(row=0, column=2, )

sc4 = Scale(root, from_=255, to=0,  resolution=1,width=Wi,length=Len,label="Amber",command=CH4)
sc4.grid(row=0, column=3, )




root.mainloop()

