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
    int goodNodes(TreeNode* root) {
        int count = 0;
        stack<pair<TreeNode*,int>> st;
        st.push({root, root->val});
        while(!st.empty()){
            pair<TreeNode*, int> p = st.top();
            st.pop();
            if(p.second <= p.first->val){
                count++;
            }
            if(p.first->left){
                st.push({p.first->left, p.first->left->val > p.second ? p.first->left->val : p.second});
            }
            if(p.first->right){
                st.push({p.first->right, p.first->right->val > p.second ? p.first->right->val : p.second});
            }
        }
        return count;
    }
};
