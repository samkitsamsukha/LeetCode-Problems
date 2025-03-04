/*
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32

Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34

Example 3:

Input: n = 21
Output: false

 

Constraints:

    1 <= n <= 107


*/

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            vector<int> a;
            for(int i = 0; pow(3, i)<=n; i++){
                a.push_back(pow(3, i));
            }
            // for(int i = 0; i<a.size(); i++){
            //     cout << a[i] << " ";
            // }
            int p = a.size()-1;
            int sum = 0;
            cout << endl;
            while(p>=0){
                // cout << "currently at " << a[p] << endl;
                if(sum == n){
                    // cout << "sum is found to be equal to " << n << endl;
                    return true;
                }
                if(sum < n && sum+a[p]<=n){
                    sum = sum + a[p];
                    // cout << "new sum = " << sum << endl;
                }
                p--;
            }
            if(sum == n){ return true; }
            return false;
        }
    };