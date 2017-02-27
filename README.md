# kerbal-wii-controller
Using wii nunchuk and arduino to send sensor data to krpc mod that controls the ship pitch and yaw. Z-button is
used to reset the xyz-values to current controller position so that preferred controller handling can be achieved.

# Steps to make anything work
1. install arduino
2. install kRPC kerbal mod
3. burn arduino sketch to arduino
4. wire wii nunchuk to arduino (3.3v and gnd, clock to analog4 and data to analog5)
5. start kerbal with sandbox, run test.py and connect the arduino

# Next steps
- Have proper handshake between python and arduino before any data is transferred
- gracefully disconnect from kerbal when not flying, now it crashes when we leave 
