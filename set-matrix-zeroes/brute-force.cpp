/*
Approach:
The steps are the following:

First, we will use two loops(nested loops) to traverse all the cells of the matrix.
If any cell (i,j) contains the value 0, we will mark all cells in row i and column j with -1 except those which contain 0.
We will perform step 2 for every cell containing 0.
Finally, we will mark all the cells containing -1 with 0.
Thus the given matrix will be modified according to the question.
*/

#include<bits/stdc++.h>
using namespace std;
class SetMatrixZeroes{
    public:
        void markRow(vector<vector<int>>&matrix, int r, int m, int n){
            for(int i = 0; i < n; i++){
                if(matrix[r][i] != 0){
                    matrix[r][i] = -1;
                }
            }
        }
        void markCol(vector<vector<int>>&matrix, int c, int m, int n){
            for(int i = 0; i < m; i++){
                if(matrix[i][c] != 0){
                    matrix[i][c] = -1;
                }
            }
        }
        void setZeroes(vector<vector<int>>&matrix){
            int m = matrix.size(), n = matrix[0].size();
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == 0){
                        markRow(matrix, i, m, n);
                        markCol(matrix, j, m, n);
                    }
                }
            }

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == -1){
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
Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
Another O(N*M) is taken to mark all the cells with -1 as 0 finally.

Space Complexity: O(1) as we are not using any extra space.
*/