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
    // Do DFSon left and right subtree , if it is a leaf add to vector
    //Match vector and check
    void tree(TreeNode* root, vector<int> &v){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr and root->right == nullptr){
            v.push_back(root->val);
            return;
        }
        tree(root->left, v);
        tree(root->right, v);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        tree(root1, a);
        tree(root2, b);
        if(a.size() != b.size()){
            return false;
        }
        int n = a.size();
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
};