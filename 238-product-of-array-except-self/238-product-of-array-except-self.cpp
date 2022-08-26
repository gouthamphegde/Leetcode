class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sp;
        vector<int> pfp(n,0);
        int suf;
        int pf;
        
        
        for(int i = 0 ; i < n ;i++){
            if(i == 0){
                sp.push_back(1);
                suf = 1;
            }
            else{
                suf = suf *nums[i-1];
                sp.push_back(suf);
            }
        }
        
        for(int i = n-1 ; i >= 0 ;i--){
            if(i == n-1){
                pfp[n-1] = 1;
                pf = 1;
            }
            else{
                pf = pf * nums[i+1];
                pfp[i] = pf;
            }
        }
        
        vector<int> ans;
        for(int i = 0 ; i < n ;i++){
            int a = sp[i] * pfp[i];
            ans.push_back(a);
        }
        
        return ans;
        
    }
};