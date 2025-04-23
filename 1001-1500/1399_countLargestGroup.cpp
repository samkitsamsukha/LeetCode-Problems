/*
You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.

 

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.

Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.

 

Constraints:

    1 <= n <= 104


*/

class Solution {
    public:
        int sod(int x){
            int s = 0;
            while(x>0){
                s = s + x%10;
                x/=10;
            }
            return s;
        }
        int countLargestGroup(int n) {
            map<int, int> mpp;
            for(int i = 1; i<=n; i++){
                mpp[sod(i)]++;
            }
            int maxi = 1;
            for(auto it:mpp){
                maxi = max(maxi, it.second);
            }
            int ans = 0;
            for(auto it:mpp){
                if(maxi == it.second){
                    ans++;
                }
            }
            return ans;
        }
    };