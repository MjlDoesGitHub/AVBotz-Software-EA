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
        // utput the least amount of coins to match our input using variable z
        change[z] = min;
    }
    return change[x];
}

int main()
{
    //Open Input File "coins2.in"
    ifstream inFile;
    inFile.open("coins2.in");

    //Check For Error
    if(inFile.fail()) {
        cerr << "Error Opening File" << endl;
        exit(1);
    } else {
        cerr<< "File Successfully Opened" << endl;
    }

    //Define Amount of Dollars as "x" and coin inputs as variables "a-d"
    float x;
    inFile >> x;
    cout << "Amount of Dollars: " << x << " dollars" << endl;
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

    //Work with coins
    int values[] = {a,b,c,d}; //Use a set of denominations (values of coins we can use)
    int n = sizeof(values)/sizeof(values[0]);
    int min = minCoins(values,n,x);
    cout<<"\nMin no. of coins required: " << min; cout <<endl;

    //Write final output to file "coins2.out"
    ofstream outFile;
    outFile.open("coins2.out");
    outFile << min;
    outFile.close();

    return 0;
}
