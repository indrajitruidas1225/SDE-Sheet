/*

only add on is - we've to find the entire array of a given row.
we'll folow the below approach to find each element.
number of element in a certain row will be equal to r itself.

The approach is to do nCr i.e n! / r! * (n - r)!
But calculating factorial for each number is not required.abort

we can break it down into easy steps

6C4 ==> 6! / 4! * 2! ==> (6*5*4*2) / (4*3*2*1) ==> r becomes the number of elements both in numerator and denominator
run a loop from 0 to r 
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int nCr(int n, int r){
            long long result = 1;
            for(int i = 0; i < r; i++){
                result = result*(n-i);
                result = result / (i + 1);
            }
            return result;
        }
        vector<int>pascalsTriange(int n){
            vector<int>result;
            for(int i = 0; i < n; i++){
                int element = nCr(n-1, i);
                result.push_back(element);
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
Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
Reason: We are calculating the element for each column. Now, there are total n columns, and for each column, the calculation of the element takes O(r) time where r is the column index.

Space Complexity: O(n)
*/