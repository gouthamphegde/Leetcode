class Solution {
public:
    int countHousePlacements(int n) {
        int fibi = 0;
        int fib1 = 1;
        long ans = 0;
        
        int k = 1e9+7;

        
        for(int i = 2 ; i <= n+2 ;i++){
            ans = (fibi % k) + (fib1 % k);
            fibi = fib1;
            fib1 = ans;
        }
        
        
        ans = ((ans%(k)) * (ans%(k)))%k;
        
        return ans;
        
        
    }
};