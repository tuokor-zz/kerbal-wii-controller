import krpc
import serial
wii = serial.Serial('/dev/ttyACM0', 19200)
conn = krpc.connect(name='wii-controller')
vessel = conn.space_center.active_vessel
print(vessel.name)

def convertPitch(wiiYaw):
    OldRange = (200 - (-200))
    NewRange = (1.0 - (-1.0))
    NewValue = (((wiiYaw - -200) * NewRange) / OldRange) + (-1.0)
    return NewValue

while True:
    values = wii.readline()
    print(values)
    decoded = values.decode('utf-8')
    values = decoded.split(',')
    yaw = convertPitch(int(values[0]))

    controller = vessel.control
    controller.yaw = yaw

