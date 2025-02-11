class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root->left) {
            TreeNode* leaf = root->left;
            while (leaf->right) leaf = leaf->right;
            if (leaf->val >= root->val) return false;
        }
        if (root->right) {
            TreeNode* leaf = root->right;
            while (leaf->left) leaf = leaf->left;
            if (root->val >= leaf->val) return false;
        }
        if (root->left && !isValidBST(root->left))
            return false;
        if (root->right && !isValidBST(root->right))
            return false;
        return true;
    }
};
