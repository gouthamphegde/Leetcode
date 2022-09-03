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
    
    
    void helper(TreeNode * root , int maxele , int & count){
        if(root -> val >= maxele){
            count++;
            maxele = root -> val;
        }
        
        if(root -> left){
            helper(root -> left , maxele , count);
        }
        
        if(root -> right){
            helper(root -> right , maxele , count);
        }
    }
    int goodNodes(TreeNode* root) {
        
        int count = 0 , maxele = root-> val;
        helper(root , maxele , count);
        return count;
    }
};