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
    int maxVal(int a, int b)
    {
        return a>b?a:b;
    }
    
    void maxDiff(TreeNode * root, int min, int max, int &maxdiff)
    {
        if(min>root->val)min = root->val;
        if(max<root->val)max = root->val;
        
        int diff = maxVal(abs(root->val-min),abs(root->val-max));
        if(diff>maxdiff)maxdiff = diff;
        
        if(root->left)maxDiff(root->left,min,max,maxdiff);
        if(root->right)maxDiff(root->right,min,max,maxdiff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int maxdiff = INT_MIN;
        maxDiff(root,INT_MAX,INT_MIN,maxdiff);
        
        return maxdiff;
    }
};