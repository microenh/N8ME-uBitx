"""
using the modified CAT request '0000D', capture a screen dump from the uBITX
"""


import serial
import time
from PIL import Image

def capture_screen_dump():
    ubitx = serial.Serial('COM5', 38400, stopbits=2, timeout=0.1)
    time.sleep(5)
    ubitx.write("0000D".encode('ascii'))
    data = ubitx.read(3 * 320 * 240)
    im = Image.frombytes("RGB", (320,240), data)
    im.save("test_new.jpg")
    


        
    
    
if __name__ == "__main__":
    capture_screen_dump()
    print ("done")
