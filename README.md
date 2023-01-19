# ArduinoBluetoothCar
Arduino Bluetooth controlled RC Car

This Arduino Bluetooth car was built while studying Robotics alongside my other projects. As I learnt more, I made changes and added upgrades to the car, both in the code and the physical build.




https://user-images.githubusercontent.com/62521980/213371227-66ea4873-f39a-4c56-b5a1-c3c3ec81bd64.mp4






Built using:
* Arduino Uno Rev3 Board
* 4x Dc Gear Motor
* 4x Wheels
* Micro Servo Motor
* 2x 9V Batteries
* L293D Motor Control Board
* HC-05 Bluetooth module
* Different LEGO pieces

# The prototype:

Before learning of Motor Control Boards, using a mobile power supply or implementing the HC-05 Bluetooth module, i was struggling to learn how to control the wheels using a joystick and an improvised motor controller made using a 95N shift register to create an H-bridge:

![image](https://user-images.githubusercontent.com/62521980/213364139-9eaee20f-b52d-4cd1-8452-a01dbbd3a639.png)

After I learnt of the Control Boards, I replaced the breadboard. The first turning system consisted of giving opposite rotations to the lateral wheels. This posed a problem, if you want to steer the car while driving, you would have to sacrifice the forward acceleration. The benefit was the ability to rotate the car from a standing position. Here I was still figuring out how to implement the Bluetooth module as it was causing problems when turned on.



https://user-images.githubusercontent.com/62521980/213365651-d733feca-c3a8-47a5-8cbb-2f0954bd036e.mp4

# First Version:

This is where I solved the Bluetooth problem. It turns out the Bluetooth Module wasn't reset after the last use, outputting corrupted values. Also, the power drain caused by the bluetooth device would leave the motors without power. Theese issues were fixed by resetting the HC-05 module and adding a second 9V battery plugged directly into the Motor Control Board to power the motors by itself, while the first battery would power the arduino board and the HC-05 bluetooth device.



https://user-images.githubusercontent.com/62521980/213367051-12279649-752e-4db0-949f-53f349f80d15.mp4



https://user-images.githubusercontent.com/62521980/213367083-9a93c7b9-547d-404b-b29b-5a1d205856a9.mp4

# Steering changes:

To fix the steering problem and be able to turn while moving, i decided to implement an axle steering system. The micro servo motor turns the axle and the wheels follow. 

* The first try resulted in a bigger front making the car unbalanced and the friction paired with the low power of the motor made the turning unreliable:

https://user-images.githubusercontent.com/62521980/213368564-751cc0fe-2e7e-44ed-a633-bf84388fa83f.mp4

* The second try was successful, resulting in a smooth and fast steering with less friction and notably smaller size:


https://user-images.githubusercontent.com/62521980/213368834-588aeb14-89b8-4739-95e4-eaef9d365030.mp4


# Final Version:

* Added changes to the code, making it possible to steer gradually to the left/right while driving. 
* Implemented a stationary mode allowing the car to rotate on the spot if needed and realign the steering angle to 0 degrees. 
* Fixed some errors that would lock the acceleration if the bluetooth module received too many imputs at the same time.
* Made a new chasis to fit all the components and wires and to distribute the weight evenly on the wheels to create enough drag, I was left with the final result:

![image](https://user-images.githubusercontent.com/62521980/213369873-7516e87c-7866-43b7-91b8-4f87307709b2.png)


