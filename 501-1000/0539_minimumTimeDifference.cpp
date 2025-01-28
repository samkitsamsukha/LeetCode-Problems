/*
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0

 

Constraints:

    2 <= timePoints.length <= 2 * 104
    timePoints[i] is in the format "HH:MM".

*/

class Solution {
public:
    static bool comparator(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    int findMinDifference(vector<string>& t) {
        vector<pair<int, int>> a;
        for(int i = 0; i<t.size(); i++){
            string hour = t[i].substr(0, 2);
            int h = stoi(hour);
            string min = t[i].substr(3, 2);
            int m = stoi(min);
            pair<int, int> temp = {h, m};
            a.push_back(temp);
        }
        sort(a.begin(), a.end(), comparator);

        // for(int i = 0; i<a.size(); i++){
        //     cout << a[i].first << ":" << a[i].second << endl;
        // }

        int ans = INT_MAX;
        for(int i = 1; i<a.size(); i++){
            int td;
            if(a[i].first == a[i-1].first) {
                td = a[i].second - a[i-1].second;
            }
            else{
                td = (60 - a[i-1].second) + (a[i].second) + (a[i].first - a[i-1].first - 1)*60;
            }
            ans = min(ans, td);
        }
        // edge
        int x = (24 - a[a.size()-1].first - 1 + a[0].first)*60 + (60 - a[a.size()-1].second + a[0].second);
        ans = min(ans, x);
        return ans;
    }
};