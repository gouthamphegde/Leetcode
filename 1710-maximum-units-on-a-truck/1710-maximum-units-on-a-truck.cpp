class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        //sort the array based on units in each box,  and then we can keep adding
        int n = boxTypes.size();
        vector<vector<int>> arr;
        for(int i = 0 ; i < boxTypes.size() ; i++){
            
            vector<int>v2{boxTypes[i][1],boxTypes[i][0]};
            arr.push_back(v2);
        }
        
        sort(arr.rbegin() , arr.rend());
        
        
        int ans = 0;
        
        int i = 0;
        while(truckSize > 0){
            if(truckSize - arr[i][1] >= 0){
                truckSize-=arr[i][1];
                ans+= (arr[i][1] * arr[i][0]);
            }
            else{
                ans+= (arr[i][0] * truckSize);
                truckSize = 0;
            }
            i++;
            if(i >= n){
                break;
            }
            
        }
        
        return ans;
    }
};