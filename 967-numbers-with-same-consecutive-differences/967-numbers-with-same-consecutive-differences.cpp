class Solution {
public:
    void dfs(int currnum , int digitsleft , int & k , vector<int> &ans){
        if(digitsleft == 0){
            ans.push_back(currnum);
            return;
        }
        
        if(currnum%10 + k <= 9){
            int num = currnum*10 + (currnum%10 + k);
            dfs(num , digitsleft-1 , k , ans);
        }
        
        if(currnum%10 - k >=0  && k!=0){
            int num = currnum*10 + (currnum%10 - k);
            dfs(num , digitsleft-1 , k , ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(int i = 1 ; i <= 9 ;i++){
            dfs(i,n-1,k,ans);
        }
        
        return ans;
    }
};