/*
Approach (Using two extra arrays):

The steps are as follows:

First, we will declare two arrays: a row array of size N and a col array of size M and both are initialized with 0.
Then, we will use two loops(nested loops) to traverse all the cells of the matrix.
If any cell (i,j) contains the value 0, we will mark ith index of row array i.e. row[i] and jth index of col array col[j] as 1. It signifies that all the elements in the ith row and jth column will be 0 in the final matrix.
We will perform step 3 for every cell containing 0.
Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for which either row[i] or col[j] is marked as 1.
Thus we will get our final matrix.
*/

#include<bits/stdc++.h>
using namespace std;
class SetMatrixZeroes{
    public:
       
        void setZeroes(vector<vector<int>>&matrix){
            int m = matrix.size(), n = matrix[0].size();
            int row[m] = {0};
            int col[n] = {0};

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == 0){
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(row[i] || col[j]){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        void printMatrix(vector<vector<int>>&matrix){ //not included in complexity analysis
            int m = matrix.size();
            int n = matrix[0].size();

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
};

int main(){
    vector<vector<int>>matrix1 = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>>matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    SetMatrixZeroes obj;
    obj.setZeroes(matrix1);
    obj.setZeroes(matrix2);

    obj.printMatrix(matrix1);
    obj.printMatrix(matrix2);
}

/*
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: O(N) is for using the row array and O(M) is for using the col array.
*/