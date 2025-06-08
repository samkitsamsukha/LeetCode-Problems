/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

Example 2:

Input: n = 2
Output: [1,2]

 

Constraints:

    1 <= n <= 5 * 104

*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int x = 1;
        for(int i = 1; i<=n; i++){
            ans.push_back(x);
            if(x*10<=n){
                x = x*10;
            }
            else{
                while(x%10==9 || x>=n){
                    x = x/10;
                }
                x++;
            }
        }
        return ans;
    }
};

