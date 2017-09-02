#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define INF 9999

using namespace std;

int minCoins(int values[],int y,int x) {
    //Using array to output the minimum amount of coins that is required for the input
    int change[x+1];
    change[0] = 0;
    int i,z;
    for(z=1;z<=x;z++) {
        int min = INF;
        for(i=0;i<y;i++) {
            if(z>=values[i] && (change[z-values[i]]+1) < min)
                min = change[z-values[i]]+1;
        }
        //Output the least amount of coins to match our input using variable z
        change[z] = min;
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
    int values[] = {1,5,10,25}; //Use a set of denominations (values of coins we can use)
    int n = sizeof(values)/sizeof(values[0]);
    int min = minCoins(values,n,x);
    cout<<"\nMin no. of coins required: " << min; cout <<endl;

    //Write final output to file "coins.out"
    ofstream outFile;
    outFile.open("coins.out");
    outFile << min;
    outFile.close();

    return 0;


}