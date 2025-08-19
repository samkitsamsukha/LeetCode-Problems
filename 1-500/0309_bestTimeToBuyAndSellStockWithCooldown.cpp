/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0

 

Constraints:

    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000

*/

class Solution {
public:
    int mem(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + mem(ind+1, 0, prices, dp), mem(ind+1, 1, prices, dp));
        }
        else{
            profit = max(prices[ind] + mem(ind+2, 1, prices, dp), mem(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return mem(0, 1, prices, dp);
    }
};