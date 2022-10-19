class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int , int> hashmap;
        for(int i = 0 ; i < nums.size() ; i++){
            hashmap.insert({nums[i] , i});
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            int diff = target - nums[i];
            if(hashmap.find(diff)!=hashmap.end()){
                int it = hashmap.at(diff);
                if(it == i){
                    continue;
                }
                return{it , i};
            }
        }
        return {};
    }        
        
        
    
};
