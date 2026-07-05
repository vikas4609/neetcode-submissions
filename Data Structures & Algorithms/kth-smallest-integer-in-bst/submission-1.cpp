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
    int kthSmallest(TreeNode* root, int k) {
        stack<pair<TreeNode*,bool>> st;
        st.push({root, false});
        while(!st.empty()){
            auto [node, visited] = st.top();
            st.pop();
            if(!node->left || visited){
                k--;
                if(k==0){
                    return node->val;
                }
            }
            if(!visited ){
                if(node->right){
                    st.push({node->right,false});
                }
            }
            if(node->left && !visited){
                st.push({node,true});
                st.push({node->left, false});
            }
        }
        return -1;
    }
};
