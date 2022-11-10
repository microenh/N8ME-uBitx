"""
uBitx screen capture
ubitx must be compiled with #USE_CAT and #USE_SCREEN_DUMP defined

type p<enter> when ready for screen capture
filename is displayed, type p<enter> for next capture
^C to end
files are named IMG000.jpg, IMG001.jpg, ...
existing files are not overwritten, image is just not saved

Note: ubitx will reset to main screen when program run.
"""


import serial
from PIL import Image



class Dumper:
    def __init__(self):
        self.i = 0
        self.ubitx = serial.Serial('COM5', 1000000, stopbits=1, timeout=0.1)
        
    def __repr__(self):
        self.ubitx.write("0000D".encode('ascii'))
        data = self.ubitx.read(3 * 320 * 240)
        im = Image.frombytes("RGB", (320,240), data)
        name = "IMG%03d.jpg" % self.i
        im.save(name)
        self.i += 1
        return name

print ("type p <enter> when ready for screen capture")
p = Dumper()
