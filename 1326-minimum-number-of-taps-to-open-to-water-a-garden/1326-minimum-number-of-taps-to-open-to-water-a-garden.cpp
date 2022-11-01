class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> v;
        for(int i=0;i<ranges.size();i++){
            if(ranges[i]==0) continue;
             int a=i-ranges[i];
            int b=i+ranges[i];
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        int cnt=0;
        int rightmost=0;
        int prevRight=0;
        int j=0;
        if(v.size()==0 || v[0][0]>0) return -1;
     
        while(j<v.size()){
            if(v[j][0]<=prevRight && v[j][1]>prevRight && prevRight<n){
                 while(j<v.size() && v[j][0]<=prevRight){
                    rightmost=max(rightmost,v[j][1]);
                     j++;
                 }
                prevRight=rightmost;
                cnt++;
            }
            else j++;
            
        }
        if(prevRight>=n) return cnt;
        return -1;
    }
};