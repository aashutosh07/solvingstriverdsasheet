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

    bool sameTree(TreeNode* a, TreeNode* b) {

        // Both are NULL
        if (a == NULL && b == NULL)
            return true;

        // One is NULL, other isn't
        if (a == NULL || b == NULL)
            return false;

        // Values are different
        if (a->val != b->val)
            return false;

        // Check both subtrees
        return sameTree(a->left, b->left) &&
               sameTree(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // subRoot is completely matched
        if (subRoot == NULL)
            return true;

        // root finished, but subRoot didn't
        if (root == NULL)
            return false;

        // Try matching from current node
        if (sameTree(root, subRoot))
            return true;

        // Try left and right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};