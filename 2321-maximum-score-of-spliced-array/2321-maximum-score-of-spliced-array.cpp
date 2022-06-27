class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
         int sum_nums1 = 0 , sum_nums2 = 0;
        int n = nums1.size();
        
        vector<int> delta(n,0);
        
        for(int i = 0 ; i < n ; i++){
            sum_nums1+=nums1[i];
            sum_nums2+=nums2[i];
            
            delta[i] = nums2[i] - nums1[i];
        }
        
        
        int maxsum1 = 0 , maxsum2 = 0 , currsum1 = 0 , currsum2 = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            currsum1+= delta[i];
            if(currsum1 < 0){
                currsum1 = 0;
            }
            
            maxsum1 = max(maxsum1,currsum1);
            
            currsum2+= (-delta[i]);
            if(currsum2 < 0){
                currsum2 = 0;
            }
            
            maxsum2 = max(maxsum2,currsum2);
            
        }
     cout << sum_nums1  << " "<< sum_nums2 << endl;

        cout << maxsum1  << " "<< maxsum2 << endl;

        maxsum1 = max(sum_nums1 , sum_nums1+maxsum1);
        maxsum2 = max(sum_nums2 , sum_nums2+maxsum2);
        
        
        return max(maxsum1 , maxsum2);
        
    }
};