class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0;
        int c = 0 , l = 0 , j = 0 , i = 0;
        int s = 0;
        
        int n = nums.size();
        
        
        for(int k = 0 ; k < n ;k++ ){
            sum+= nums[k];
        }
        
    
        
        s = sum - x;
        
        if(s == 0){
            return n;
        }
        
        if(s < 0){
            return -1;
        }
        
        while(j < n){
            c+= nums[j];
            
            while(c >= s){
                if(c == s){
                    l = max(l , j - i +1);
                }
                c-=nums[i];
                i++;
            }
            
            j++;
        }
        if(l == 0){
            return -1;
        }
        
        return n - l;
    }
};