class Solution {
public:
    bool isItPossible(string word1, string word2) {
        
        
        unordered_map<char,int> mp1,mp2;
     //store unique char with frequency in map for both strings
        for(char ch:word1) mp1[ch]++;
        for(char ch:word2) mp2[ch]++;
        
        for(char i='a'; i<='z'; i++){

            for(char j='a'; j<='z'; j++){
               // if letters exist in word1 and word2
              if(mp1.count(i) && mp2.count(j)){
                
                //swap i and j
                if(--mp1[i]==0) mp1.erase(i);
                mp1[j]++;
                if(--mp2[j]==0) mp2.erase(j);
                mp2[i]++;
               //check
                if(mp1.size()==mp2.size()){
                    return true;
                }
               //restore
               if(--mp1[j]==0) mp1.erase(j);
               mp1[i]++;
               if(--mp2[i]==0) mp2.erase(i);
               mp2[j]++;


              }
            }
        }

        return false;
    }
};