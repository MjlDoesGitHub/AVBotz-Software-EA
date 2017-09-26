#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ifstream inFile;
ofstream outFile;

//using intergers for this one... not precise

int minimalCoins(int values[],int y,int x) {
    //using array/table to output the minimum amount of coins that is required for the input

    //change[z]is minimum number of coins needed for the variable z, therefore change[x] will have the output
    int change[x+1]; //input plus 1
    change[0] = 0; //if input is 0 then make chance equal to 0

    int i,z; //using these variables for the upcoming function

    //format the array/table to be infinite to make all inputs possible
    for(z=1;z<=x;z++) { //calculate if 1 is less than or equal to the input value then repeat this function to find all required minimum coins from 1 to 9999 (infinite)
        int minimal = 9999; //infinite values in the array/table for inputs

        //locate the coins that are smaller than z
        for(i=0;i<y;i++) {
            if(z>=values[i] && (change[z-values[i]]+1) < minimal) //change[z] indicates the minimum amount of coins required
                minimal = change[z-values[i]]+1;
        }
        //output the least amount of coins to match our input using variable z
        change[z] = minimal;
    }
    return change[x];
}

int main()
{
    //check for error
    if(inFile.fail()) {
        cout << "\nError Opening File" << endl;
        exit(1);
    } else {
        cout<< "\nFile Successfully Opened" << endl;
    }

    //Open Input File "coins.in"
    cout << "\nPlease input values into 'sum.in'" << endl;
    inFile.open("coins.in");

    //define input coin value as "x"
    float x;
    inFile >> x;
    cout << "Input Coin Value: " << x << " cents" << endl;

    //calculate coin values
    int values[] = {1,5,10,25}; //set of denominators or coins we can use
    int y = sizeof(values)/sizeof(values[0]); //used to test the values
    int minimal = minimalCoins(values,y,x);
    cout<<"\nMinimal usage of coins required: " << minimal; cout <<endl;

    //write final output to file "coins.out"
    cout << "See file 'coins.out' for final output" << endl;
    outFile.open("coins.out");
    outFile << minimal;
    outFile.close();

    return 0;
}
