/*
Convert a non-negative integer num to its English words representation.

    Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

    Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

    Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

class Solution {
public:
    string trimSpaces(const string& str) {
        istringstream iss(str);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        ostringstream oss;
        copy(words.begin(), words.end(), ostream_iterator<string>(oss, " "));
            string result = oss.str();
            if (!result.empty()) {
                result.pop_back();
            }
            return result;
        }
    string convert3(int x) {
        vector<string> ones = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> eens = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string t = "";
        if (x == 0) {
            return "";
        }
        if (x > 0 && x < 10) {
            return ones[x - 1];
        }
        if (x == 10) {
            return tens[0];
        }
        if (x > 10 && x < 20) {
            return eens[x - 11];
        }
        if (x >= 20 && x < 100) {
            t = tens[(x / 10) - 1];
            if (x % 10 != 0) {
                t += " " + ones[(x % 10) - 1];
            }
            return t;
        }
        int dig1 = x / 100;
        if (dig1 != 0) t = t + ones[dig1 - 1] + " Hundred ";
        int dig2 = x % 100;
        if (dig2 == 0) {
            return t.substr(0, t.size() - 1);
        }
        if (dig2 == 10) {
            t += tens[0];
        } 
        else if (dig2 > 10 && dig2 < 20) {
            t += eens[dig2 - 11];
        } 
        else if (dig2 >= 20) {
            t += tens[(dig2 / 10) - 1];
            if (dig2 % 10 != 0) {
                t += " " + ones[(dig2 % 10) - 1];
            }
        } 
        else if (dig2 < 10 && dig2 != 0) {
            t += ones[dig2 - 1];
        }
        return t;
    }

    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        string s = "";
        if (num < 1000) {
            s = s + convert3(num);
        } else if (num < 1000000) {
            int hundreds = num % 1000;
            int thousands = num / 1000;
            s = s + convert3(thousands) + " Thousand " + convert3(hundreds);
        } else if (num < 1000000000) {
            int hundreds = num % 1000;
            cout << hundreds << endl;
            int thousands = (num / 1000) % 1000;
            cout << thousands << endl;
            int millions = num / 1000000;
            cout << millions << endl;
            if (thousands == 0) {
                s = s + convert3(millions) + " Million " + convert3(hundreds);
            } else {
                s = s + convert3(millions) + " Million " + convert3(thousands) + " Thousand " + convert3(hundreds);
            }
        } else if (num < 1000000000000) {
            int hundreds = num % 1000;
            int thousands = (num / 1000) % 1000;
            int millions = (num / 1000000) % 1000;
            int billions = num / 1000000000;
            s = s + convert3(billions) + " Billion ";
            if (millions != 0) {
                s = s + convert3(millions) + " Million ";
            }
            if (thousands != 0) {
                s = s + convert3(thousands) + " Thousand ";
            }
            s = s + convert3(hundreds);
        }
        return trimSpaces(s);
    }
};