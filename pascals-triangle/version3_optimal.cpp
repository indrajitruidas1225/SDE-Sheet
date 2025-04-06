/*

we'll just use version 2 inside a loop
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int>pascalsTriange(int n){
            vector<int>result;
            int ans = 1;
            result.push_back(ans);
            for(int i = 1; i < n; i++){
                ans = ans*(n - i);
                ans = ans / i;
                result.push_back(ans);
            }
            return result;
        }
        vector<vector<int>>driver(int n){
            vector<vector<int>>res;
            for(int i = 1; i <= n; i++){
                vector<int>ans = pascalsTriange(i);
                res.push_back(ans);
            }
            return res;
        }
        void printArray(vector<vector<int>>arr){
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < arr[i].size(); j++){
                    cout << arr[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
};

int main(){
    Solution obj;
    vector<vector<int>>ex1 = obj.driver(5);
    vector<vector<int>>ex2 = obj.driver(6);

    obj.printArray(ex2);
}

/*
Time Complexity: O(N^2)

Space Complexity: O(n^2) for the vector
*/