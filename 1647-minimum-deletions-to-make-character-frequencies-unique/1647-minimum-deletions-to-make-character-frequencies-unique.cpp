class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> freq(26,0);
        
        for(auto i : s){
            freq[i - 'a']++;
        }
        
        
        unordered_set<int> st;
        int deleteCount  = 0;
        
        for(int i = 0 ; i < 26 ;i++){
            while(freq[i] && st.find(freq[i])!= st.end()){
                freq[i]--;
                deleteCount++;
            }
            
            st.insert(freq[i]);
        }
        
        
        return deleteCount;
        
    }
};