/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

 

Constraints:

    1 <= k <= 100
    1 <= prices.length <= 1000
    0 <= prices[i] <= 1000

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
    int maxProfit(int k, vector<int>& arr) {
        vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return mem(0, 1, k, arr, dp);   
    }
};