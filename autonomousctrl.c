#pragma config(Sensor, S2,     sonarSensor,         sensorSONAR)
#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma platform(NXT)

const int MS_FOR_EACH_INCH = 25;
const int MS_FOR_EACH_DEGREE = 6;

void goXInches(int x) {
	bool directionForward = NULL;

	if (x >= 0) {
		directionForward = true;
	} else if (x < 0){
		directionForward = false;
	}

	x = abs(x);

	for (int i = 0; i < x; i++)
    {
      motor[motorD] = directionForward ? -50 : 50;
      motor[motorE] = directionForward ? 50 : -50;

      wait1Msec(MS_FOR_EACH_INCH);

      motor[motorD] = 0;
      motor[motorE] = 0;

    }
	}


void turnXDegrees(int x) {

	bool turnRight = NULL;

	if (x >= 0) {
		turnRight = true;
	} else if (x < 0){
		turnRight = false;
	}

	for (int i = 0; i < x; i++)
    {
      motor[motorD] = turnRight ? -25 : 25; //the motors are a little weird bc of gears. don't switch dese values.
      motor[motorE] = turnRight ? -25 : 25;

      wait1Msec(MS_FOR_EACH_DEGREE);

      motor[motorD] = 0;
      motor[motorE] = 0;

    }
	}

task main()
{

   while(true)
   {
     	nxtDisplayTextLine(4, "%d", SensorValue[sonarSensor]);
     	nxtDisplayTextLine(5, (SensorValue[sonarSensor] > 25) ? "Nothing in proximity!" : "AHH something is close!");

      if(SensorValue[sonarSensor] > 25) {
      	goXInches(5);
      	wait1Msec(500);
      } else {
      	turnXDegrees(180);
      	wait1Msec(1000);
    	}


   }

}
