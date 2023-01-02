class Solution {
public:
    bool isArmstrong(int n) {
        long long res = 0;
        int i = n;
        string s = to_string(n);
        int k = s.length();
        while(i > 0){
            int j = i%10;
            res+= pow(j,k);
            i = i/10;
        }
        
        return n == res;
    }
};