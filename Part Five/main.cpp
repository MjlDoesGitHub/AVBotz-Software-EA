#include <iostream>
#include "pid.hpp"

using namespace std;


int main()
{

    double processVariable; //pv = desired height
    double setPoint = getHeight(); //sp = current height

    cout<<"Initial height: "<< endl ;
    cin >> setPoint;
    cout << "Desired Height: ";
    cin >> processVariable;

    /*
     * Code should start here.
     */

    double KP = 0;
    double KI = 0;
    double KD = 0;
    double DT = 0.1;

    double minimum = -255;
    double maximum = 255;

    double output = KP + KI + KD;

    double error = setPoint - processVariable;
    double prevError = 0;

    while(processVariable != setPoint) {

        //error calculation
        prevError = error;
        error = setPoint - processVariable;

        //proportional
        KP = KP * error;

        //intergral
        KI = KI + error * DT;

        //derivative
        KD = (error - prevError) / DT;

        //output & setting thrust
        setThrust(output);
        setPoint = setPoint - output*DT;
        prevError = error;

        //set output within minimum - maximum range
        if(output > maximum) {
            output = maximum;
        } else if(output < minimum) {
            output = minimum;
        }

        cout << output << endl;
    }
}