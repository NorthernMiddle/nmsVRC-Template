using namespace vex;

extern brain Brain;

////////////////////////////
//
// VEXcode devices
//
////////////////////////////////////////////////

// sensors

// motors
extern motor lfMotor;
extern motor rfMotor;
extern motor lbMotor;
extern motor rbMotor;

// motor_group
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;


// drivetrain
extern drivetrain Drivetrain;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
