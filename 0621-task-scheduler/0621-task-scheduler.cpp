class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        
        for(int i = 0 ; i < tasks.size() ;i++){
            v[tasks[i]-'A']++;
        }
        
        sort(v.begin() , v.end() , greater<int> ());
        
        int maxfreq = v[0] - 1;
        
        int ideltime = n * maxfreq;
        
        for(int i = 1 ; i < 26 ; i++){
            ideltime-= min(maxfreq , v[i]);
        }
        
        return ideltime > 0 ? ideltime + tasks.size() : tasks.size();
    }
};