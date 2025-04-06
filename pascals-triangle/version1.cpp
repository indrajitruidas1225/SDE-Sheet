/*
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
        int pascalsTriange(int r, int c){
            int element = nCr(r-1, c-1);
            return element;
        }
};

int main(){
    Solution obj;
    cout<<obj.pascalsTriange(5,3)<<"\n";
    cout<<obj.pascalsTriange(6,2)<<"\n";
}

/*
Time Complexity: O(c), where c = given column number.
Reason: We are running a loop for r times, where r is c-1.

Space Complexity: O(1) as we are not using any extra space.
*/