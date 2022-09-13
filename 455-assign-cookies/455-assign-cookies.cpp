class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int ck = s.size()-1, ch = g.size()-1, result = 0;
        while(ck > -1 && ch > -1){
            if(g[ch] <= s[ck]) ck--, result++;
            ch--;
        }
        return result;
    }
};