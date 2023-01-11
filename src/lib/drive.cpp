/**
  * DESCRIPTION: Set drive voltage
  * this power setting is used for both tank and arcade drive
  *
  */
void set_drive_pow(int l, int r) {
  LeftFront.spin(fwd, l * SCALE, voltageUnits::mV);
  LeftBack.spin(fwd, l * SCALE, voltageUnits::mV);
  RightFront.spin(fwd, r * SCALE, voltageUnits::mV);
  RightBack.spin(fwd, r * SCALE, voltageUnits::mV);
}

///////////////////////////////////////////////////
//
//  ---| ARCADE DRIVE  |---
//
///////////////////////////////////////////////////////////////////////////////

/** 
  * NAME: right_arcade_drive()
  * DESCRIPTION: right arcade drive function definition
  * Function for arcade drive for right joystick. 
  *
  */
void right_arcade_drive()
{
  // fwd Axis2 + Axis1
  int l_joy = abs(Controller1.Axis2.value() + Controller1.Axis1.value()) > 
    DEADBAND ? Controller1.Axis2.value() + Controller1.Axis1.value() : 0;

  // turn Axis2 - Axis1
  int r_joy = abs(Controller1.Axis2.value() - Controller1.Axis1.value()) > 
    DEADBAND ? Controller1.Axis2.value() - Controller1.Axis1.value() : 0;

  set_drive_pow(l_joy, r_joy);
}

/** 
  * NAME: arcadeDrive()
  * DESCRIPTION: callback function for thread
  * Function for arcade drive for right joystick. 
  * Function to be registered to a thread for continuous use.
  * Function registered to thread arcadeDrive_t
  *
  */
int arcadeDrive()
{
  int count = 0;
  while(true)
  {
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("Arcade Drive has iterated %d times", count);
    count++;

    right_arcade_drive();
    
    // You must sleep threads by using the 'this_thread::sleep_for(unit in
    // msec)' command to prevent this thread from using all of the CPU's
    // resources.
    this_thread::sleep_for( 25 );
  }

  // A threads's callback must return an int, even though the code will never
  // get here. You must return an int here. Threads can exit, but this one does not.
  return( 0 );
}

///////////////////////////////////////////////////
//
// tank drive
//
///////////////////////////////////////////////////////////////////////////////

/** 
  * NAME: tank_drive()
  * DESCRIPTION: tank drive function definition
  * Function for tank drive
  *
  */
/*
void tank_drive()
{

  int l_joy = abs(Controller1.Axis3.value()) > 
    DEADBAND ? Controller1.Axis3.value() : 0;

  int r_joy = abs(Controller1.Axis2.value()) > 
    DEADBAND ? Controller1.Axis2.value() : 0;

  set_drive_pow(l_joy, r_joy);
}
*/


/** 
  * NAME: tankDrive()
  * DESCRIPTION: callback function for thread
  * Function for tank drive
  * Function to be registered to a thread for continuous use.
  * Function registered to thread tankDrive_t
  *
  */
/*
int tankDrive(){
  int count = 0;
  while(true)
  {
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print("Tank Drive has iterated %d times", count);
    count++;


    tank_drive();
    //  You must sleep threads by using the 'this_thread::sleep_for(unit in
    //  msec)' command to prevent this thread from using all of the CPU's
    //  resources. 
    this_thread::sleep_for( 25 );
  }

  // A threads's callback must return an int, even though the code will never
  // get here. You must return an int here. Threads can exit, but this one does not.
  return( 0 );
}

*/
