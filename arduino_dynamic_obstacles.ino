// Include the AccelStepper library:
#include <AccelStepper.h>


// Define stepper motor connections and motor interface type. Motor interface type must be
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // Set the maximum speed in steps per second:
  stepper.setMaxSpeed(3000);
}

void loop() {
  // Set the current position to 0:
  stepper.setCurrentPosition(0);
  // Run the motor forward at 2000 steps/second until the motor reaches 20000 steps:
  while(stepper.currentPosition() != 20000)
  {
    stepper.setSpeed(2000);
    stepper.runSpeed();
  }
  delay(1000);
  // Reset the position to 0:
  stepper.setCurrentPosition(0);
  // Run the motor backwards at 2000 steps/second until the motor reaches -20000 steps:
  while(stepper.currentPosition() != -20000)
  {
    stepper.setSpeed(-2000);
    stepper.runSpeed();
  }
  delay(1000);
}

