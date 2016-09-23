import serial
import time

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

x = 1
while True:
    dmxdata = senddmx(dmxdata, 1, 255)
    time.sleep(.5)
    dmxdata = senddmx(dmxdata, 1, 0)
    dmxdata = senddmx(dmxdata, 2, 255)
    time.sleep(.5)
    dmxdata = senddmx(dmxdata, 2, 0)
    dmxdata = senddmx(dmxdata, 3, 255)
    time.sleep(.5)
    dmxdata = senddmx(dmxdata, 3, 0)
    dmxdata = senddmx(dmxdata, 4, 255)
    time.sleep(.5)
    dmxdata = senddmx(dmxdata, 4, 0)

x + 1

print "DMX channel 1 at Full"
