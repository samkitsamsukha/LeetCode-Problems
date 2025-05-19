/*
Given a 0-indexed string s, permute s to get a new string t such that:

    All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
    The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].

Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

Example 1:

Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.

Example 2:

Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".

 

Constraints:

    1 <= s.length <= 105
    s consists only of letters of the English alphabet in uppercase and lowercase.


*/

class Solution {
    public:
        string sortVowels(string s) {
            int a = 0, e = 0, il = 0, o = 0, u = 0, A = 0, E = 0, I = 0, O = 0, U = 0;
            for(int i = 0; i<s.length(); i++){
                if(s[i]=='a') a++;
                else if(s[i]=='e') e++;
                else if(s[i]=='i') il++;
                else if(s[i]=='o') o++;
                else if(s[i]=='u') u++;
                else if(s[i]=='A') A++;
                else if(s[i]=='E') E++;
                else if(s[i]=='I') I++;
                else if(s[i]=='O') O++;
                else if(s[i]=='U') U++;
            }
            vector<char> temp;
            while(A--) temp.push_back('A');
            while(E--) temp.push_back('E');
            while(I--) temp.push_back('I');
            while(O--) temp.push_back('O');
            while(U--) temp.push_back('U');
            while(a--) temp.push_back('a');
            while(e--) temp.push_back('e');
            while(il--) temp.push_back('i');
            while(o--) temp.push_back('o');
            while(u--) temp.push_back('u');
            int j = 0;
            int i = 0;
            for(int i = 0; i<s.length() && j<temp.size(); i++){
                if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U'){
                    continue;
                }
                else{
                    s[i] = temp[j];
                    j++;
                }
            }
            return s;
        }
    };