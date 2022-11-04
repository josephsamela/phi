import serial
import time
import json

ser = serial.Serial(
    port='COM3',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=0)

print("connected to: " + ser.portstr)
count=1

time.sleep(1)

buf = ''

while True:
    line = ser.readline()

    # Decode bytestrings into string
    try:
        data = line.decode("utf-8")
    except UnicodeDecodeError:
        buf = buf[1:]
        continue

    # Concatenate data to buffer
    buf += data

    # Find and print out any complete packets
    if '\r\n' in buf:
        packets = buf.split('\r\n')
        for p in packets:
            try:
                packet = json.loads(p)
            except ValueError:
                buf = p
                continue 

            print(packet)
    
    time.sleep(0.1)

ser.close()
