/*
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
*/


//Top don approach
class Solution {
public:

    int MOD = 1e9+7;
    int t[31][1001];
    int solve(int n, int k, int target){
        if(target<0){
            return 0;
        }
        if(t[n][target]!=-1){
            return t[n][target];
        }
        
        if(n==0){
            return target==0;
        }
        int ways=0;
        for(int face=1;face<=k;face++){
            ways = (ways+solve(n-1,k,target-face))%MOD;
        }

        return t[n][target]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(t,-1,sizeof(t));
        return solve(n,k,target);
    }
};
//Bottom up approach
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>t(n+1,vector<int>(target+1));
        t[0][0]=1;
        int MOD = 1e9+7;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){

                int ways=0;
                for(int face=1;face<=k;face++){
                    if(j-face>=0){
                        ways = (ways + t[i-1][j-face])%MOD;
                    }
                }

                t[i][j]=ways;
            }
        }
        return t[n][target];
    }
};
