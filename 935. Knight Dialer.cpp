/*
https://leetcode.com/problems/knight-dialer/description/?envType=daily-question&envId=2023-11-27

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, 
or two squares horizontally and one square vertically (with both forming the shape of an L).
Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
*/

class Solution {
public:
    int MOD = 1e9 + 7;
    int t[5001][10];
    vector<vector<int>>adj = {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };

    int solve(int n, int cell){
        if(n==0){
            return 1;
        }
        if(t[n][cell]!=-1){
            return t[n][cell];
        }
        int ans=0;
        for(auto nextCell : adj[cell]){
            ans = (ans+solve(n-1,nextCell))%MOD;
        }
        return t[n][cell]=ans;
    }

    int knightDialer(int n) {
        memset(t,-1,sizeof(t));
        int result=0;
        for(int cell=0;cell<=9;cell++){

            result = (result + solve(n-1,cell))%MOD;
        }

        return result;
    }
};
