/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 105

*/

class Solution {
public:
    int mem(int i, int j, int k, vector<int>& arr, vector<vector<vector<int>>>& dp){
        if(k == 0) return 0;
        if(arr.size() == i) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(j){
            return dp[i][j][k] = max(-arr[i]+mem(i+1, 0, k, arr, dp), mem(i+1, 1, k, arr, dp));
        }
        return dp[i][j][k] = max(arr[i]+mem(i+1, 1, k-1, arr, dp), mem(i+1, 0, k, arr, dp));
    }
    int tab(vector<int>& arr){
        vector<vector<vector<int>>> dp(arr.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i = arr.size()-1; i>=0; i++){
            for(int j = 0; j<=1; j++){
                for(int k = 1; k<=2; k++){
                    if(j){
                        dp[i][j][k] = max(-arr[i]+dp[i+1][0][k], dp[i+1][1][k]);
                    }
                    else{
                        dp[i][j][k] = max(arr[i]+dp[i+1][1][k-1], dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& arr) {
        vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return (0, 1, 2, arr, dp);   
    }
};