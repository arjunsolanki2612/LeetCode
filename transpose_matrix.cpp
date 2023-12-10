/*
https://leetcode.com/problems/transpose-matrix/description/?envType=daily-question&envId=2023-12-10
867. Transpose Matrix

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>newMat(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               newMat[j][i] = matrix[i][j]; 
            }
        }
        return newMat;
    }
};
