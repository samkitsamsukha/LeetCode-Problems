/*
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

 

Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.

Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.

 

Constraints:

    1 <= intervals.length <= 105
    intervals[i].length == 2
    1 <= lefti <= righti <= 106

*/

class Solution {
public:
    static bool comparator(pair<int, char> a, pair<int, char> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    int minGroups(vector<vector<int>>& nums) {
        vector<pair<int, char>> x;
        int ans = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            x.push_back({nums[i][0], 'S'});
            x.push_back({nums[i][1], 'E'});
        }
        sort(x.begin(), x.end(), comparator);
        // for(int i = 0; i<x.size(); i++){
        //     cout << x[i].first << x[i].second << endl;
        // }
        for(int i = 0; i<x.size(); i++){
            if(x[i].second == 'S'){
                ans++;
                maxi = max(maxi, ans);
            }
            else{
                ans--;
            }
        }
        if(maxi == 0) return 1;
        return maxi;
    }
};