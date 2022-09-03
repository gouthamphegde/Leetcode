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
         queue<pair<TreeNode*, int>> q; //<node, maxtill now>
        q.push({root, root->val});
        int count=0; 
        while(!q.empty()){
            auto [node, maxVal]=q.front();
            q.pop();
            if(node->val==maxVal)
                count++;
            if(node->left)
                q.push({node->left, max(maxVal, node->left->val)});
            if(node->right)
                q.push({node->right, max(maxVal, node->right->val)});
        }
        return count;
    }
};