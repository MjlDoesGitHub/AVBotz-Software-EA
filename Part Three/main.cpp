#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

    ifstream inFile;
    ofstream outFile;

int minimalCoins(int values[],int y,int x) {
    //using array (change[x]) to output the minimum amount of coins that is required for the input
    int change[x+1];
    change[0] = 0;
    int i,z;
    for(z=1;z<=x;z++) { //for z is less than or equal to x, repeat this function
        int minimal = 9999; //inf array values
        for(i=0;i<y;i++) { //go through all coins smaller than x
            if(z>=values[i] && (change[z-values[i]]+1) < minimal) //recursion
                minimal = change[z-values[i]]+1;
        } 
        change[z] = minimal; //set the final output
        
    }
    return change[x];
}


int main() {

    //check for error when opening file
    if(inFile.fail()) {
        cout << "\nError Opening File" << endl;
        exit(1);
    } else {
        cout<< "\nFile Successfully Opened" << endl;
    }

    //open input file "coins.in"
    cout << "\nPlease input values in file 'coins2.in'" << endl;
    inFile.open("coins2.in");

    //define amount of dollars as "x" and coin inputs as variables "a-d"
    //basically taking a set of denominations except from the input file similar to the last problem
    float x;
    inFile >> x;
    cout << "\nAmount of Dollars: " << x << " dollars" << endl;
    int a;
    inFile >> a;
    cout << "Input Coin Value #1: " << a << " coins" << endl;
    int b;
    inFile >> b;
    cout << "Input Coin Value #2: " << b << " coins" << endl;
    int c;
    inFile >> c;
    cout << "Input Coin Value #3: " << c << " coins" << endl;
    int d;
    inFile >> d;
    cout << "Input Coin Value #4: " << d << " coins" << endl;

    //work with coins
    int values[] = {a,b,c,d}; //use a set of coin values we can use
    int n = sizeof(values)/sizeof(values[0]); //calculate the number of elements in an array
    int minimal = minimalCoins(values,n,x); //coins we can use, elements in array, amount of dollars
    cout << "\nMin no. of coins required: " << minimal; cout << endl;

    //write final output to file "coins2.out"
    cout << "Read file 'coins2.out' for final output" << endl;
    outFile.open("coins2.out");
    outFile << minimal;
    outFile.close();

    return 0;

}
