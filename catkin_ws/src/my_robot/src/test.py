
import serial

uart = serial.Serial(
    port = '/dev/ttyACM0',
    baudrate = 115200,
    parity = serial.PARITY_NONE,

    stopbits = serial.STOPBITS_ONE,

    bytesize = serial.EIGHTBITS
)
for x in xrange (0,1000):
    uart.write([chr(170),chr(13),chr(5), chr(0), chr(100)])
