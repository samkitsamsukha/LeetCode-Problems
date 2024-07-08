/*
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

    For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.

Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

    Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.

    Example 2:

Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.

    Constraints:

2 <= n <= 1000
1 <= time <= 1000
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = time%(n-1);
        int cycles = time/(n-1);
        if(time<n){
            return time+1;
        }
        else if(cycles%2==1){
            return n-pos;
        }
        else if(cycles%2==0){
            return pos+1;
        }
        return 0;
    }
};

class Solution {
public:
    int passThePillow(int n, int time) {
        int pos = 1;
        int dir = 1;
        while(time--){
            if(pos==1){
                pos++;
                dir = 1;
            }
            else if(pos<n && dir == 1){
                pos++;
            }
            else if(pos==n){
                pos--;
                dir = -1;
            }
            else if(pos<n && dir == -1){
                pos--;
            }
        }
        return pos;
    }
};