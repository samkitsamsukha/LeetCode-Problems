/*
You are given an array words of n strings. Each string has length m and contains only lowercase English letters.

Two strings s and t are similar if we can apply the following operation any number of times (possibly zero times) so that s and t become equal.

    Choose either s or t.
    Replace every letter in the chosen string with the next letter in the alphabet cyclically. The next letter after 'z' is 'a'.

Count the number of pairs of indices (i, j) such that:

    i < j
    words[i] and words[j] are similar.

Return an integer denoting the number of such pairs.

 

Example 1:

Input: words = ["fusion","layout"]

Output: 1

Explanation:

words[0] = "fusion" and words[1] = "layout" are similar because we can apply the operation to "fusion" 6 times. The string "fusion" changes as follows.

    "fusion"
    "gvtjpo"
    "hwukqp"
    "ixvlrq"
    "jywmsr"
    "kzxnts"
    "layout"

Example 2:

Input: words = ["ab","aa","za","aa"]

Output: 2

Explanation:

words[0] = "ab" and words[2] = "za" are similar. words[1] = "aa" and words[3] = "aa" are similar.

 

Constraints:

    1 <= n == words.length <= 105
    1 <= m == words[i].length <= 105
    1 <= n * m <= 105
    words[i] consists only of lowercase English letters.

*/

class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        map<string, long long> mpp;
        for(int i = 0; i<words.size(); i++){
            string s = words[i];
            if(s[0] != 'a'){
                int turns = (26-(s[0]-'a'))%26;
                // cout << turns << " are required for " << s << endl;
                for(int j = 0; j<s.length(); j++){
                    int newval = (s[j]-'a'+turns)%26;
                    s[j] = 'a'+newval;
                }
                words[i] = s;
                // cout << "new s " << s << endl;
            }
            if(mpp[words[i]]>0){
                ans+=mpp[words[i]];
            }
            mpp[words[i]]++;
        }
        return ans;
    }
};