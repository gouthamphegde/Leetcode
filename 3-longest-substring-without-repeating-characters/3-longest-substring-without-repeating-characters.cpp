class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() == 1){
            return 1;
        }
        int ans = 0;
        
        int n = s.length();
        
        int i = 0 , j = 0;
        int chars[256];
        
        for(int i = 0 ; i < 256 ;i++){
            chars[i] = -1;
        }        
        while(j < n){
            if(chars[s[j]]!= -1){
                i = max(chars[s[j]]+1,i);

            }
            
            chars[s[j]] = j;
            ans = max(ans , j-i+1);
            j++;
        }
        
        
        return ans;
        
    }
};