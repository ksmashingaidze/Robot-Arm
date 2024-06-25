#include <Servo.h>

// K.S. Mashingaidze
// Robot Arm controlled by Arduino Due
// Base, shoulder, elbow, and claw controlled by four select switches and a potentiometer for servo position

// Define servo objects for the robot arm
Servo base_servo;
Servo shoulder_servo;
Servo elbow_servo;
Servo claw_servo;

// Define key variables
String curr_servo = "base";    // Initialize a variable to store the current servo selection
int pot_val = 0;               // Initialize a variable to store the potentiometer reading
int servo_angle = 0;           // Initialize a variable to store the setpoint servo angle
int old_servo_angle = 0;       // Initialize a variable to store the old servo angle
// Initialize variables to store the state of the base, shoulder, elbow, and claw servo select switches respectively
int sw1_val = 0;
int sw2_val = 0;
int sw3_val = 0;
int sw4_val = 0;

void setup() {
  // Setup
  Serial.begin(115200);
  delay(1000);
  analogReadResolution(8);         // Initialize the onboard ADC in 8-bit mode, i.e. (0-255)
  Serial.println("Robot On.");     // Begin

  // Configure input pins for the potentiometer
  pinMode(A7,INPUT);

  // Configure input pins for the select switches
  pinMode(A8,INPUT);
  pinMode(A9,INPUT);
  pinMode(A10,INPUT);
  pinMode(A11,INPUT);

  // Attach servo objects to pins on the Arduino Due
  base_servo.attach(9);
  shoulder_servo.attach(10);
  elbow_servo.attach(11);
  claw_servo.attach(12);

  // Set initial servo positions
  servo_angle = 135;
  shoulder_servo.write(servo_angle);
  servo_angle = 45;
  elbow_servo.write(servo_angle);
  servo_angle = 180;
  claw_servo.write(servo_angle);

}

void loop() {
  // Main code running repeatedly

  // Check for servo select button presses
  sw1_val = digitalRead(A8);
  sw2_val = digitalRead(A9);
  sw3_val = digitalRead(A10);
  sw4_val = digitalRead(A11);
  // Select servo based on which button has been pressed
  if (sw1_val == HIGH){
    Serial.println("Base servo selected.");
    curr_servo = "base";
  }
  else if (sw2_val == HIGH){
    Serial.println("Shoulder servo selected.");
    curr_servo = "shoulder";
  }
  else if (sw3_val == HIGH){
    Serial.println("Elbow servo selected.");
    curr_servo = "elbow";
  }
  else if (sw4_val == HIGH){
    Serial.println("Claw servo selected.");
    curr_servo = "claw";
  }

  // Update the servo angle based on the pot reading
  pot_val = analogRead(A7);                      // Read potentiometer
  servo_angle = map(pot_val, 0, 255, 0, 180);    // Map the potentiometer value from (0-255) to (0-180)
  // Update the selected servo smoothly from its old position to its new position
  // If the base servo is selected
  if (curr_servo == "base"){
    old_servo_angle = base_servo.read();
    if (servo_angle >= old_servo_angle){
      for (int i=old_servo_angle; i<=servo_angle; i++){
        base_servo.write(i);
        delay(15);
      }
    }
    else if (servo_angle < old_servo_angle){
      for (int i=old_servo_angle; i>=servo_angle; i--){
        base_servo.write(i);
        delay(15);
      }
    }
  }
  // Else, if the shoulder servo is selected
  else if (curr_servo == "shoulder"){
    old_servo_angle = shoulder_servo.read();
    if (servo_angle >= old_servo_angle){
      for (int i=old_servo_angle; i<=servo_angle; i++){
        shoulder_servo.write(i);
        delay(15);
      }
    }
    else if (servo_angle < old_servo_angle){
      for (int i=old_servo_angle; i>=servo_angle; i--){
        shoulder_servo.write(i);
        delay(15);
      }
    }
  }
  // Else, if the elbow servo is selected
  else if (curr_servo == "elbow"){
    old_servo_angle = elbow_servo.read();
    if (servo_angle >= old_servo_angle){
      for (int i=old_servo_angle; i<=servo_angle; i++){
        elbow_servo.write(i);
        delay(15);
      }
    }
    // Else, if the claw servo is selected
    else if (servo_angle < old_servo_angle){
      for (int i=old_servo_angle; i>=servo_angle; i--){
        elbow_servo.write(i);
        delay(15);
      }
    }
  }
  else if (curr_servo == "claw"){
    old_servo_angle = claw_servo.read();
    if (servo_angle >= old_servo_angle){
      for (int i=old_servo_angle; i<=servo_angle; i++){
        claw_servo.write(i);
        delay(15);
      }
    }
    else if (servo_angle < old_servo_angle){
      for (int i=old_servo_angle; i>=servo_angle; i--){
        claw_servo.write(i);
        delay(15);
      }
    }
  }
  
}
