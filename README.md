# Robot-Arm
Multi-joint robot arm implemented using Arduino Due development board.
* Servo 1: Base, signal line connected to pin 9, select switch is sw1.
* Servo 2: Shoulder, signal line connected to pin 10, select switch is sw2.
* Servo 3: Elbow, signal line connected to pin 11, select switch is sw3.
* Servo 4: Claw, signal line connected to pin 12, select switch is sw4.


                  |¯¯¯\
                  III\\ \----------_____-----------
                      |||Servo 4|||     | Servo 3 |
                  ___///IIIIIIIIIII¯¯¯¯¯IIIIIIIIIII
                  IIII/                   |     |
                                          |     |
                                          |     |
                                          |     |
                                          |     |
                                          |     |
                                          |     |
                                        IIIIIIIIIII
                                        | Servo 2 |
                                        \\\\\\\\\\\
                                        | Servo 1 |
                                        ¯¯¯¯¯¯¯¯¯¯¯
                            
