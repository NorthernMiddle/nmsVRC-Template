
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


// motors
motor lfMotor = motor(PORT1, ratio6_1, false);
motor lbMotor = motor(PORT2, ratio6_1, false);
motor rfMotor = motor(PORT19, ratio6_1, true);
motor rbMotor = motor(PORT20, ratio6_1, true);

// motor_groups
motor_group LeftDriveSmart = motor_group(lfMotor, lbMotor);
motor_group RightDriveSmart = motor_group(rfMotor, rbMotor);

// drivetrains
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 299.24, 294.89399999999995, 39.878, mm, 2);

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
  // nothing to initialize
}
