class Solution {
public:
    void dfs(map<int,vector<int>> & g , set<int> &s , int a , vector<int> & ans){
        if(s.find(a)!=s.end()){
            return;
        }
        ans.push_back(a);
        s.insert(a);
        
        for(auto x : g[a]){
            dfs(g,s,x,ans);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> g;
        
        
        for(auto p : adjacentPairs){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        
        int first;
        for(auto it : g){
            if(it.second.size() == 1){
                first = it.first;
            }
        }
        
        set<int> s;
        vector<int> ans;
        dfs(g,s,first,ans);
        
        return ans;
    }
};