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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        res.push_back(root->val);
        while(!q.empty()){
            int sz=q.size();
            int rightmost;
            while(sz--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    rightmost=node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    rightmost=node->right->val;
                }
            }
            res.push_back(rightmost);
        }
        res.pop_back();
        return res;
    }
};
