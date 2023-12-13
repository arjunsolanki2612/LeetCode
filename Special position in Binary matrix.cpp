/*
https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2023-12-13

Given an m x n binary matrix mat, return the number of special positions in mat.
A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Example 1:
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

Example 2:
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int special = 0;
        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){

                if(mat[row][col]==1){
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){

                if(mat[row][col]==1 && rowCount[row]==1 && colCount[col]==1){
                    special++;
                }
            }
        }

        return special;

    }
};
