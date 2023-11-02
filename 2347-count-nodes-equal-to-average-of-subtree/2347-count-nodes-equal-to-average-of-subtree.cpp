/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
    pair<int,int>solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> leftSum = solve(root->left);
        pair<int,int> rightSum = solve(root->right);

        int totalsum = leftSum.first+rightSum.first+root->val;
        int totalcount = leftSum.second+rightSum.second+1;
        int avg = totalsum/totalcount;
        if(avg==root->val){
            sum+=1;
        }

        return {totalsum,totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return sum;
    }
};