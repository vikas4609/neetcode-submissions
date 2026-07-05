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
    int preIndex = 0;
    int inIndex = 0;

    TreeNode* node(vector<int>& preorder, vector<int>& inorder, int lim){
        if(preIndex >= preorder.size()) return nullptr;
        if(inorder[inIndex] == lim){//
            inIndex++;//1
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(preorder[preIndex]);
        preIndex++;
        newNode->left = node(preorder, inorder, newNode->val);//1
        newNode->right = node(preorder, inorder, lim);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return node(preorder, inorder, INT_MAX);//1000
    }
};
