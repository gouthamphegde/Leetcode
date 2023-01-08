class Solution {
public:
    int distinct(vector<int>&nums)
    {
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            if(nums[i]!=0) ans++;
        }
        //cout<<ans<<endl;
        return ans;
    }
    
    bool isItPossible(string word1, string word2)
    {
         vector<int>mp1(26,0),mp2(26,0);
        
        for(auto w:word1) mp1[w-'a']++;
        for(auto w:word2) mp2[w-'a']++;
        
        
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(mp1[i] && mp2[j])
                {
                    
                
                mp1[i]--;
                mp1[j]++;
                mp2[i]++;
                mp2[j]--;
                if(distinct(mp1)==distinct(mp2)) return true;
                
                mp1[i]++;
                mp1[j]--;
                mp2[i]--;
                mp2[j]++;
                    
                }
            }
        }
        
        return false;
        
    }
};
