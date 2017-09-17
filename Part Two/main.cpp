//Dear AVBotz, I couldn't find out how to work with decimals for this assignment. However, putting whole numbers will work just fine. Say you put 99 in the input file instead of 0.99, it will return the same output for both.

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

ifstream inFile;
ofstream outFile;

int minimalCoins(int values[],int y,int x) {
    //using array to output the minimum amount of coins that is required for the input
    int change[x+1];
    change[0] = 0;
    int i,z;
    for(z=1;z<=x;z++) {
        int minimal = 9999;
        for(i=0;i<y;i++) {
            if(z>=values[i] && (change[z-values[i]]+1) < minimal)
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

    //work with coins
    int values[] = {1,5,10,25}; //values of coins we can use)
    int n = sizeof(values)/sizeof(values[0]);
    int minimal = minimalCoins(values,n,x);
    cout<<"\nMinimal usage of coins required: " << minimal; cout <<endl;

    //write final output to file "coins.out"
    cout << "See file 'coins.out' for final output" << endl;
    outFile.open("coins.out");
    outFile << minimal;
    outFile.close();

    return 0;
}
