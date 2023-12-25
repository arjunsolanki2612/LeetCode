/*
https://leetcode.com/problems/decode-ways/description/?envType=daily-question&envId=2023-12-25
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

// recursion with memo
class Solution {
public:
    int t[101];
    int solve(int i, string&s, int &n){
        if(t[i]!=-1){
            return t[i];
        }
        if(i==n){
            return t[i]=1;
        }
        if(s[i]=='0'){
            return 0; //not able to split
        }

        int take_ith_char = solve(i+1,s,n);
        int take_two_char = 0;
        if(i+1<n){
            if(s[i]=='1'|| s[i]=='2'&&s[i+1]<= '6'){
                take_two_char = solve(i+2,s,n);
            }
        }
        return t[i]=take_ith_char + take_two_char;
    }
    int numDecodings(string s) {
        int n = s.size();
        
        memset(t,-1,sizeof(t));
        return solve(0,s,n);

    
    }
};

//bottom up
class Solution {
public:
    //Bottom up
    int numDecodings(string s) {
        int n = s.size();
        vector<int>t(n+1,0);
        //t[i] means decode ways of string s from index i to n
        t[n]=1; // if(i==n) return 1
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                t[i]=0;
            }
            else
            {
                t[i]=t[i+1]; // solve(i+1);

                if(i+1<n){
                    if(s[i]=='1' || s[i]=='2' && s[i+1]<='6'){
                        t[i]+=t[i+2]; //solve(i+2);
                    }
                }
            }
        }
        return t[0]; // return ways from t[0 to n] ie full string;
    }
};
