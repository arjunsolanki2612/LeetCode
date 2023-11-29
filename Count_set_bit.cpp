/*
https://leetcode.com/problems/number-of-1-bits/description/?envType=daily-question&envId=2023-11-29
191. Number of 1 Bits
Easy
Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

*/

// Approach 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        //to set rightmost set bit unset do n & (n-1);
        int count=0;
        while(n){
            n = n & (n-1);
            count++;
        }
        return count;
    }
};

// Approach 2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            int ans = n&1;
            if(ans){
                count++;
            }
            n=n>>1;

        }
        return count;
    }
};
