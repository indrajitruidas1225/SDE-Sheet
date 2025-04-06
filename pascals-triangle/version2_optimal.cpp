/*

here we found a formula.

answer at any position = previous answer * (n - column number) / column number;
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
};

int main(){
    Solution obj;
    vector<int>ex1 = obj.pascalsTriange(5);
    vector<int>ex2 = obj.pascalsTriange(6);

    // for(int i = 0; i < ex1.size(); i++){
    //     cout<<ex1[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i = 0; i < ex2.size(); i++){
    //     cout<<ex2[i]<<" ";
    // }
}

/*
Time Complexity: O(N) where N = given row number. Here we are using only a single loop.

Space Complexity: O(n) for the vector
*/