class Solution {
public:
    vector<vector<int>>directions = {{1,0},{0,1}};
    
    int path(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        int totalPath = 0;
        if(dp[i][j]!=-1){
             return dp[i][j];
        }

       
        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            totalPath += path(new_i,new_j,m,n,dp);
        }
        return dp[i][j] = totalPath;
    }

     int uniquePaths(int m, int n) {
        vector<vector<int>>dp (m,vector<int>(n,-1));
        return path(0,0,m,n,dp);
        
    }
};