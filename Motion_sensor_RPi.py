import serial
from subprocess import Popen, PIPE
right_sequence = '''key Right'''
def keypress(sequence):
	p = Popen(['xte'], stdin=PIPE)
	p.communicate(input=sequence)

ser = serial.Serial('/dev/ttyUSB0', 9600)
strIn = "wtv"
while 1:
	strIn = ser.readline()
	if strIn == 'success\r\n':
		keypress(right_sequence)
