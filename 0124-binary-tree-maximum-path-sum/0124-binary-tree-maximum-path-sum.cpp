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
    int maxi = INT_MIN;
    int maximum(TreeNode* root){
        if(root == NULL) return 0;

        int leftSum = maximum(root->left);
        int rightSum = maximum(root->right);
        maxi = max(maxi , max(0,leftSum)+max(0,rightSum)+root->val);
        return (root->val) + max(0,max(leftSum,rightSum));
    }
    int maxPathSum(TreeNode* root) {
        maximum(root);
        return maxi;
    }
};