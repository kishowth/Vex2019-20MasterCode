#include "vex.h"

using namespace vex;
//KISHOWTH


// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
vex::controller driverController = vex::controller(); 

//motor Instantiations
//DriveTrain
vex::motor LeftFrontDrive = vex::motor(1, false);
vex::motor RightFrontDrive = vex::motor(2, false);
vex::motor LeftBackDrive = vex::motor(3, false);
vex::motor RightBackDrive = vex::motor(4, false); 

//intake
vex::motor leftIntake = vex::motor(5, false);
vex::motor rightIntake = vex::motor(6, false); 

//arm
vex::motor armContol = vex::motor(6, false);


//pre auton
void pre_auton( void ) {/*pre auton*/}


//autonomous methods
void autonomous( void ){}
void autonomous2( void ){}
void autonomous3( void ){}
void autonomous4( void ){}
void autonomous5( void ){}
void autonomous6( void ){}

//user Control function
void usercontrol( void ) {
  
  while (1) {
    //drive train Control
    LeftBackDrive.spin(vex::directionType::fwd, driverController.Axis3.position(), vex::velocityUnits::pct);
    LeftFrontDrive.spin(vex::directionType::fwd, driverController.Axis3.position(), vex::velocityUnits::pct);
    RightBackDrive.spin(vex::directionType::fwd, driverController.Axis2.position(), vex::velocityUnits::pct);
    RightFrontDrive.spin(vex::directionType::fwd, driverController.Axis3.position(), vex::velocityUnits::pct);

    //intake control
    if(driverController.ButtonL2.pressing()){
      leftIntake.spin(directionType::fwd,100, velocityUnits::pct);
      rightIntake.spin(directionType::fwd,100, velocityUnits::pct);
    }
    else if(driverController.ButtonL1.pressing()){
      leftIntake.spin(directionType::fwd,100, velocityUnits::pct);
      rightIntake.spin(directionType::fwd,100, velocityUnits::pct);
    }
    else{
      leftIntake.spin(directionType::fwd,0, velocityUnits::pct);
      rightIntake.spin(directionType::fwd,0, velocityUnits::pct);
    }


    //arm control
    if(driverController.ButtonR1.pressing()){
      armContol.spin(directionType::fwd,100, velocityUnits::pct);
    }
    else if(driverController.ButtonR2.pressing()){
      armContol.spin(directionType::rev,100, velocityUnits::pct);
    }
    else{
      armContol.spin(directionType::fwd,0, velocityUnits::pct);
    }


}


    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }



//DO NOT CHANGE !!
int main() {
    //set correct auto
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}