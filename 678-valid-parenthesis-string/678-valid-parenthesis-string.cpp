class Solution {
public:
    bool checkValidString(string s) {
        int l = 0 , star = 0;
        
        for(int i = 0 ; i < s.length() ;i++){
            if(s[i] == '('){
                l++;
            }
            else if(s[i] == '*'){
                star++;
            }
            else{
                if(l > 0){
                    l--;
                }
                else if(star > 0){
                    star--;
                }
                else{
                    return false;
                }
            }
        }
        star = 0 , l = 0;
        
        for(int i = s.length()-1 ; i>=0 ;i--){
            if(s[i] == ')'){
                l++;
            }
            else if(s[i] == '*'){
                star++;
            }
            else{
                if(l > 0){
                    l--;
                }
                else if(star > 0){
                    star--;
                }
                else{
                    return false;
                }
            }
        }
        
        return true;
        
    }
};