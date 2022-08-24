class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        int sum = 0;
        for(int i = 0 ; i < sz ;i++){
            sum+= nums[i];
        }
        
        int leftsum = 0;
        
        for(int i = 0 ; i < sz ;i++){
            if(leftsum == sum -nums[i]){
                return i;
            }
            leftsum+= nums[i];
            sum-=nums[i];
        }
        
        return -1;
    }
};