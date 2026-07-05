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
    int height(TreeNode* root){
        if(!root) return 0;
        int x = height(root->left);
        int y = height(root->right);
        return x>y ? x+1 : y+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int x = diameterOfBinaryTree(root->left);
        int y = diameterOfBinaryTree(root->right);
        int z = x>y ? x : y;
        int a = height(root->left) + height(root->right);
        // if(height(root->left)){
        //     a = a + height(root->left); 
        // }
        // if(height(root->right)){
        //     a = a + height(root->right); 
        // }
        return a>z ? a : z; 
    }
};
