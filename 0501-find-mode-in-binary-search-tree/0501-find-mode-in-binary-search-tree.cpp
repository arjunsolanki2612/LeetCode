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

// second apporac without extra space
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
        int currEle = 0;
        int currFreq = 0;
        int maxFreq = 0;
    void inorder(TreeNode* root,vector<int>&ans){
        if(root!=NULL){
            inorder(root->left,ans);
            // kya current element root ki value k barabar h
            if(root->val==currEle){
                currFreq++;
            }else{
                currEle = root->val;
                currFreq=1;
            }
            // kya current freq max freq se badi h to hume koi naya number mila h
            if(currFreq>maxFreq){
                ans={};
                maxFreq=currFreq;

            }
            if(currFreq==maxFreq){
                ans.push_back(currEle);
            }
            inorder(root->right,ans);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        
        inorder(root,ans);
        return ans;

        
    }
};
