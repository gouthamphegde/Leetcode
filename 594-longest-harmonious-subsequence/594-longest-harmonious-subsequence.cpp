class Solution {
public:
    int findLHS(vector<int>& nums) {
        
         unordered_map<int , int> mp;
        int max_len = 0;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] += 1;
        }
        
        sort(nums.begin() , nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] == 1){
                max_len = max(max_len , mp[nums[i]] + mp[nums[i-1]]);
            }
        }     
        return max_len;    
    }
        
    
};