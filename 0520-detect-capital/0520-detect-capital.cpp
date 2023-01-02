class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int count = 0;
        bool firstl = false;
        for(int i = 0 ; i < n ;i++){
           if(word[i] - 65 <= 25){
               count++;
               if(i == 0){
                   firstl = true;
               }
           } 
        }
        
        if(count == 0){
            return true;
        }
        if(count == n){
            return true;
        }
        
        if(count == 1 && firstl){
            return true;
        }
        
        return false;
    }
};