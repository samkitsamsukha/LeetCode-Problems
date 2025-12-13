/*
You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

    code[i]: a string representing the coupon identifier.
    businessLine[i]: a string denoting the business category of the coupon.
    isActive[i]: a boolean indicating whether the coupon is currently active.

A coupon is considered valid if all of the following conditions hold:

    code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
    businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
    isActive[i] is true.

Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

 

Example 1:

Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

Output: ["PHARMA5","SAVE20"]

Explanation:

    First coupon is valid.
    Second coupon has empty code (invalid).
    Third coupon is valid.
    Fourth coupon has special character @ (invalid).

Example 2:

Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

Output: ["ELECTRONICS_50"]

Explanation:

    First coupon is inactive (invalid).
    Second coupon is valid.
    Third coupon has invalid business line (invalid).

 

Constraints:

    n == code.length == businessLine.length == isActive.length
    1 <= n <= 100
    0 <= code[i].length, businessLine[i].length <= 100
    code[i] and businessLine[i] consist of printable ASCII characters.
    isActive[i] is either true or false.

*/

class Solution {
public:
    bool check(string s){
        if(s=="") return false;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='_' || isalpha(s[i]) || isdigit(s[i])){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<string> joinArrays(const vector<string>& a, const vector<string>& b, const vector<string>& c, const vector<string>& d) {
        vector<string> result;
        result.reserve(a.size() + b.size() + c.size() + d.size());
        result.insert(result.end(), a.begin(), a.end());
        result.insert(result.end(), b.begin(), b.end());
        result.insert(result.end(), c.begin(), c.end());
        result.insert(result.end(), d.begin(), d.end());
        return result;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> elec;
        vector<string> groc;
        vector<string> phar;
        vector<string> rest;
        for(int i = 0; i<n; i++){
            if(!isActive[i]) continue;
            if(businessLine[i] == "electronics"){
                if(check(code[i])){
                    elec.push_back(code[i]);
                }
            }
            if(businessLine[i] == "grocery"){
                if(check(code[i])){
                    groc.push_back(code[i]);
                }
            }
            if(businessLine[i] == "pharmacy"){
                if(check(code[i])){
                    phar.push_back(code[i]);
                }
            }
            if(businessLine[i] == "restaurant"){
                if(check(code[i])){
                    rest.push_back(code[i]);
                }
            }
        }
        sort(elec.begin(), elec.end());
        sort(groc.begin(), groc.end());
        sort(phar.begin(), phar.end());
        sort(rest.begin(), rest.end());
        return joinArrays(elec, groc, phar, rest);
    }
};