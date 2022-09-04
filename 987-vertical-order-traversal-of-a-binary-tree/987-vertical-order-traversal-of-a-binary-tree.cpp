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
    map<int,map<int,vector<int>>> mp;

void compute(TreeNode* root,int ind,int level)
{
    if(!root) return;
    mp[ind][level].push_back(root->val);
    compute(root->left,ind-1,level+1);
    compute(root->right,ind+1,level+1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
        if(!root) return ans;
    compute(root,0,0);
    for(auto &i:mp )
    {   
        vector<int> temp;
        for(auto &j:i.second)
        {
            sort(j.second.begin(),j.second.end());
            for(auto &k:j.second)
                temp.push_back(k);
        }
        ans.push_back(temp);
    }
    return ans;
}
};