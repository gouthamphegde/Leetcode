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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        long long sum = 0 , count = 0;
        
        vector<double> ans;
        
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
            
            if(!temp){
                ans.push_back(double(sum)/count);
                sum = 0;
                count = 0;
                q.push(NULL);
                if(!q.front()){
                    break;
                }
                
            }
            else{
                if(temp-> left){
                    q.push(temp->left);
                }
                if(temp-> right){
                    q.push(temp-> right);
                }
                
                count++;
                sum+=temp-> val;
            }
        }
        
        
        return ans;
        
    }
};