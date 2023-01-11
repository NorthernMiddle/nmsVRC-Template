
#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

///////////////////////////////
//
// VEXcode device constructors
//
////////////////////////////////////////////////////

// sensors
inertial DrivetrainInertial = inertial(PORT15);
rotation RotationSensor = rotation(PORT18, true);
optical OpticalSensor01 = optical(PORT17);

// motors
motor lfMotor = motor(PORT1, ratio6_1, false);
motor lbMotor = motor(PORT2, ratio6_1, false);
motor rfMotor = motor(PORT19, ratio6_1, true);
motor rbMotor = motor(PORT20, ratio6_1, true);

// motor_groups
motor_group LeftDriveSmart = motor_group(lfMotor, lbMotor);
motor_group RightDriveSmart = motor_group(rfMotor, rbMotor);

// constant variables for drivetrain
const double wheelTravel = 299.24;          // 3.25-in wheels
const double trackWidth = 349.25;           // 13.75-inches
const double wheelBase = 241.30;            // 9.5-inches
const double externalGearRatio = 2.0;       // 72-tooth gear : 36-tooth gear

// drivetrain
smartdrive Smartdrive = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, wheelTravel, trackWidth, wheelBase, distanceUnits::mm, externalGearRatio);

/////////////////////////////////
//
// VEXcode generated functions
//
///////////////////////////////////////////////
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}
