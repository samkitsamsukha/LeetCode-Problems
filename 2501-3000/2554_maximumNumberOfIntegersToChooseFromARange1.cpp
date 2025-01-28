/*
You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

    The chosen integers have to be in the range [1, n].
    Each integer can be chosen at most once.
    The chosen integers should not be in the array banned.
    The sum of the chosen integers should not exceed maxSum.

Return the maximum number of integers you can choose following the mentioned rules.

 

Example 1:

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.

Example 2:

Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.

Example 3:

Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.

 

Constraints:

    1 <= banned.length <= 104
    1 <= banned[i], n <= 104
    1 <= maxSum <= 109


*/

class Solution {
public:
    int maxCount(vector<int>& a, int n, int maxSum) {
        sort(a.begin(), a.end());
        long long s = 1;
        long long c = 0;
        long long sum = 0;
        while(sum<maxSum && s<=n){
            cout << "s is " << s << endl;
            bool flag = true;
            long long l = 0;
            int r = a.size()-1;
            while(l<=r){
                long long mid = (l+r)/2;
                if(a[mid] == s){
                    flag = false;
                    break;
                }
                else if(a[mid] < s){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            if(flag){
                sum = sum + s;
                if(sum <= maxSum){
                    c++;
                    cout << "s is taken " << s << endl;
                    cout << "sum is now " << sum << endl;
                }

            }
            s++;
        }
    return c;
    }
};