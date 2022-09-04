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
    
    void helper(TreeNode* root , vector<double>& sums , vector<int> & counts , int l){
        if(!root){
            return;
        }
        if(sums.size() <= l){
            sums.push_back(0);
        }
        if(counts.size() <= l){
            counts.push_back(0);
        }
        
        
        sums[l]+=root -> val;
        counts[l]++;
        
            helper(root-> left , sums , counts , l+1);
            helper(root-> right , sums , counts , l+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums;
        vector<int> counts;
        
        helper(root , sums , counts , 0);
        
        for(int i = 0 ; i < sums.size() ;i++){
            sums[i]/=counts[i];
        }
        
        
        return sums;
    }
};