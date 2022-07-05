class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> HashSet;
        
        for(auto it : nums){
            HashSet.insert(it);
        }
        
        
        int longestStreak = 0;
        
        for(auto num : HashSet){
            if(!HashSet.count(num-1)){
                int currentNum = num;
                int currentStreak = 1;
                
                while(HashSet.count(currentNum+1)){
                    currentStreak++;
                    currentNum++;
                }
                
                longestStreak = max(longestStreak , currentStreak);
            }
        }
        
        
        return longestStreak;
    }
};