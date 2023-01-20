class Solution {
public:
    int M = 11000;
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0] = 1;
        int sum=0,cnt=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum=(sum + nums[i])%k;
            if(sum<0){
                sum =  (sum +(M/k)*k)%k;
            }
            m[sum]++;
        }
        for(auto i:m){
            cnt+=i.second*(i.second-1)/2;
        }
        return cnt;
    }
};
