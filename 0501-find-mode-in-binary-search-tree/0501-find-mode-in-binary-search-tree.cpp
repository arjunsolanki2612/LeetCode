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
unordered_map<int, int>mp;
    void preorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        mp[root->val]++;
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
       vector<int>ans;
        preorder(root);
        int maxFreq=0;
        for(auto i:mp){
            if(i.second>maxFreq){
                maxFreq=i.second;
                ans = {};
                ans.push_back(i.first);
            }else if(i.second==maxFreq){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};