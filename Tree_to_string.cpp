

/**
https://leetcode.com/problems/construct-string-from-binary-tree/description/?envType=daily-question&envId=2023-12-08
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
    string tree2str(TreeNode* root) {
      // root ka left and right ka string le aa and then root me append krde

      if(root==NULL){
          return "";
      }

      string result = to_string(root->val); // root (L)(R)

      string LEFT = tree2str(root->left);
      string RIGHT = tree2str(root->right);

      if(!root->left && !root->right){
          return result;
      }

      if(root->left==NULL){
          return result + "()" + "(" + RIGHT + ")";
      }
      if(root->right==NULL){
          return result + "(" + LEFT + ")";
      }


      return result + "(" + LEFT + ")" + "(" + RIGHT + ")";
    }
};
