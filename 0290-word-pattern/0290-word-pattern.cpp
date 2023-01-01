class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        int i;
        string str="";
        for(i=0;i<s.length();i++){
            if(s[i]==' '){
                words.push_back(str);
                str="";
            }else{
                str+=s[i];
            }
        }

        words.push_back(str);

        int n1 = pattern.length(), n2 = words.size();

        if(n1!=n2){
            return false;
        }else{
            map<char,string>mp;
            map<string,char>mp1;
            for(i=0;i<n1;i++){
                if(mp.find(pattern[i])!=mp.end()){
                    if(mp[pattern[i]]!=words[i]){
                        return false;
                    }
                }else{
                    if(mp1.find(words[i])==mp1.end()){
                        mp1[words[i]] = pattern[i];
                        mp[pattern[i]]=words[i];
                    }else{
                        return false;
                    }

                }
            }
            return true;
        }
    }
    
};