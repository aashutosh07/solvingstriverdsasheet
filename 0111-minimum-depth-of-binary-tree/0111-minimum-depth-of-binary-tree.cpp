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
    int minDepth(TreeNode* root) {
        //base case
        if(root == nullptr){
            return 0;
        }
         
        //left is null 
        if(root->left == NULL){
            return 1 + minDepth(root->right);
        }
         
        //right is null 
        if(root->right == NULL){
            return 1 + minDepth(root->left);
        }
         
        //both right and left exists
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return 1 + min(left,right);
      

    }
};