#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {

    int r, c; //Rows, columns

    //Open input file "sum.in"
    cout << "Please input values into 'sum.in'" << endl;
    ifstream inFile;
    inFile.open("sum.in");
    inFile >> r >> c;

    //Check for error
    if (inFile.fail()) {
        cout << "Error Opening File" << endl;
        exit(1);
    } else {
        cout << "File Successfully Opened" << endl;
    }

    //Specify rows and columns
    cout << "Amount of Rows: " << r << " Rows" << endl;
    cout << "Amount of Columns: " << c << " Columns" << endl;

    //Display and define grid + read input file 'sum.in'
    int matrix[r][c];
    int nums[r][c];
    int thirty = 1<<30;
    for (int i = 0; i<r; i++) {
        for (int j = 0; j<c; j++){
            inFile >> matrix[i][j];
            nums[i][j] = thirty;
            cout << matrix[i][j] << "\t";

        }
        cout << endl;
    }

    /* Find minimum values nearby in the matrix
     * Quick References:
     * https://stackoverflow.com/questions/5643659/how-to-insert-pairint-int-into-queue
     * http://www.cplusplus.com/reference/queue/queue/pop/
     * http://www.cplusplus.com/reference/queue/queue/push/
    */
    queue<pair<int, int>> pairq;
    pairq.push(make_pair(0, 0));

    nums[0][0] = matrix[0][0];

    while (!pairq.empty()) {
        int x = pairq.front().first;
        int y = pairq.front().second;
        pairq.pop();

        if (x == r-1 && y == c-1){
            continue;
        }

        if (y<r-1 && nums[x][y+1] > nums[x][y]+matrix[x][y+1]) {
            pairq.push(make_pair(x, y+1));
            nums[x][y+1] = nums[x][y] + matrix[x][y+1];
        }

        if (x>0 && nums[x-1][y] > nums[x][y]+matrix[x-1][y]) {
            pairq.push(make_pair(x-1, y));
            nums[x-1][y] = nums[x][y] + matrix[x-1][y];
        }

        if (y>0 && nums[x][y-1] > nums[x][y]+matrix[x][y-1]) {
            pairq.push(make_pair(x, y-1));
            nums[x][y-1] = nums[x][y]+matrix[x][y-1];
        }

        if (x<r-1 && nums[x+1][y] > nums[x][y]+matrix[x+1][y]) {
            pairq.push(make_pair(x+1, y));
            nums[x+1][y] = nums[x][y] + matrix[x+1][y];
        }

    }

    //Write final output to file "sum.out"
    ofstream outFile;
    outFile.open("sum.out");
    int output = nums[r-1][c-1];
    outFile << output << endl;
    outFile.close();
    cout << "Minimum cost path from top left to bottom right: " << output << endl;
    cout << "Check 'sum.out' for minimum cost path" << endl;

    return 0;
}