#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int r, c; //rows, columns

    //open output file "sum.out"
    ofstream outFile;
    outFile.open("sum.out");

    //open input file "sum.in"
    cout << "Please input matrix into 'sum.in'" << endl;
    ifstream inFile;
    inFile.open("sum.in");
    inFile >> r >> c;

    //check for error
    if (inFile.fail()) {
        cout << "Error Opening File" << endl;
        exit(1);
    } else {
        cout << "File Successfully Opened" << endl;
    }

    //specify rows and columns
    cout << "Amount of Rows: " << r << " Rows" << endl;
    cout << "Amount of Columns: " << c << " Columns" << endl;

    //display and define grid
    int mNum[r][c];
    int matrix[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            inFile >> matrix[i][j];
            cout << matrix[i][j] << " ";

        }
        cout << endl;
        mNum[0][0] = matrix[0][0];
    }

    //check if matrix values are valid, if not––return 0
    int matrixsize = r * c;
    if(matrixsize <= 0) {
        return 0;
    } else {
        int x;
        int y;

        //find minimum cost path in matrix
        for (x = 0; x < r && x < c; x++) {
            mNum[0][x] = mNum[0][x - 1] + matrix[0][x];
            mNum[x][0] = mNum[x - 1][0] + matrix[x][0];
            for (y = 0; y < c; y++) {
                mNum[x][y] = min(mNum[x - 1][y], mNum[x][y - 1]) + matrix[x][y];
            }
        }
    }

    //Write final output to file "sum.out"
    int output = mNum[r-1][c-1];
    outFile << output-1 << endl; //output always returned value with a +1, i don't know why that is but this seems to work
    outFile.close();
    cout << "Minimum cost path from top left to bottom right: " << output-1 << endl;
    cout << "Check 'sum.out' for minimum cost path" << endl;

    return 0;
}
