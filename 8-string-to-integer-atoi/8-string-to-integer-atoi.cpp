class Solution {
public:
    int myAtoi(string s) {
        
        long ans = 0;
        int len = s.length();
        int sign = 1;
        int i = 0 ;
        while(i < len && s[i] == ' '){
            i++;
            
        }
        
        s = s.substr(i);
        
        if(s[0] == '-' || s[0] == '+'){
            i = 1;
        }
        else{
            i = 0;
        }
        
        if(s[0] == '-'){
            sign = -1;
        }
        
        
        while(i < s.length()){
            if(s[i]== ' ' || !isdigit(s[i])){
                break;
            }
            ans = ans*10 + (s[i]-'0');
            
            if(sign == -1 && ans*sign < INT_MIN) return INT_MIN;
            if(sign == 1 && ans * sign > INT_MAX) return INT_MAX;
            i++;
        }
        
        return sign*ans;
    }
};