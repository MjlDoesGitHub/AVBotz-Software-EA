//Dear AVBotz, I couldn't find out how to work with decimals for this part. However, putting whole numbers will work just fine. Say you put 99 in the input file instead of 0.99, it will return the same output for both.

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int minimalCoins(int values[],int y,int x) {
    //Using array to output the minimum amount of coins that is required for the input
    int change[x+1];
    change[0] = 0;
    int i,z;
    for(z=1;z<=x;z++) {
        int minimal = 9999;
        for(i=0;i<y;i++) {
            if(z>=values[i] && (change[z-values[i]]+1) < minimal)
                minimal = change[z-values[i]]+1;
        }
        //Output the least amount of coins to match our input using variable z
        change[z] = minimal;
    }
    return change[x];
}

int main()
{
    //Open Input File "coins.in"
    ifstream inFile;
    inFile.open("coins.in");

    //Check For Error
    if(inFile.fail()) {
        cerr << "Error Opening File" << endl;
        exit(1);
    } else {
        cerr<< "File Successfully Opened" << endl;
    }

    //Define Input Coin Value as "x"
    float x;
    inFile >> x;
    cout << "Input Coin Value: " << x << " cents" << endl;

    //Work with coins
    int values[] = {1,5,10,25}; //Use a set of coin values we can use
    int n = sizeof(values)/sizeof(values[0]);
    int minimal = minimalCoins(values,n,x);
    cout<<"\nMinimal useage of coins required: " << minimal; cout <<endl;

    //Write final output to file "coins.out"
    ofstream outFile;
    outFile.open("coins.out");
    outFile << minimal;
    outFile.close();

    return 0;
}
