/*
In the previous approach, the time complexity is minimal as the traversal of a matrix takes at least O(N*M)(where N = row and M = column). In this approach, we can just improve the space complexity. So, instead of using two extra matrices row and col, we will use the 1st row and 1st column of the given matrix to keep a track of the cells that need to be marked with 0. But here comes a problem. If we try to use the 1st row and 1st column to serve the purpose, the cell matrix[0][0] is taken twice. To solve this problem we will take an extra variable col0 initialized with 1. Now the entire 1st row of the matrix will serve the purpose of the row array. And the 1st column from (0,1) to (0,m-1) with the col0 variable will serve the purpose of the col array.
*/

#include<bits/stdc++.h>
using namespace std;
class SetMatrixZeroes{
    public:
       
        void setZeroes(vector<vector<int>>&matrix){
            int m = matrix.size(), n = matrix[0].size();
            int col0 = 1;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == 0){
                        matrix[i][0] = 0;
                        if(j != 0){
                            matrix[0][j] = 0;
                        }
                        else{
                            col0 = 0;
                        }
                    }
                }
            }
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    if(matrix[i][j] != 0){
                        if(matrix[i][0] == 0 || matrix[0][j] == 0){
                            matrix[i][j] = 0;
                        }
                    } 
                }
            }
            if(col0 == 0){
                for(int i = 0; i < n; i++){
                    matrix[0][i] = 0;
                }
            }
            if(matrix[0][0] == 0){
                for(int i = 0; i < m; i++){
                    matrix[i][0] = 0;
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
Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

Space Complexity: O(1) as we are not using any extra space.
*/