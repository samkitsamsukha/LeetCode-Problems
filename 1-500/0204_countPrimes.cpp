/*
Given an integer n, return the number of prime numbers that are strictly less than n.

    Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    Example 2:

Input: n = 0
Output: 0

    Example 3:

Input: n = 1
Output: 0
 
    Constraints:

0 <= n <= 5 * 106
*/

class Solution {
public:
    int countPrimes(int n) {
        
        bool *isPrime = new bool[n];
        for(int i = 2; i<n; i++){
            isPrime[i] = true;
        }
        for(int i = 2; i*i <= n ; i++){
            if(isPrime[i] == true){
                for(int j=i*i; j<n; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        int c = 0;
        for(int i=2; i<n; i++){
            if(isPrime[i] == true){
                c++;
            }
        }
        delete[] isPrime;
        return c;
    }
};

/*
Intuition

An array isPrime is created to store true and false values whether a number is prime or not. We use the Sieve Of Eratosthenes approach for this problem, where we mark all multiples of prime numbers as false.

Approach

The size of isPrime array is n and initially all the values are set to be true. We start the outer loop from 2, and since 2 is marked as true the if(isPrime[i] == true) is satisfied and we move to the inner loop where j starts from 2x2=4 and post this it keeps converting multiples of 2 as false; We increment value of j by j = i+j because we want to jump over to 4, 6, 8 and not on 3, 5, 7 etc. The reason for taking initial value j = i*i is that we are willing to start from 9 when it comes to 3 since 6 has already been marked. Similarly while outer loop is 5, we will start from 25, because 10, 15 and 20 are already marked false.

Complexity
Time complexity:
O(Nlog(logN)) viz equivalent to O(N)

Space complexity:
O(N)
*/