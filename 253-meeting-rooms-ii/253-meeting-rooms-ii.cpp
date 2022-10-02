class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n , 0);
        vector<int> last(n , 0);
        
        for(int i = 0 ; i < n ; i++){
            start[i] = intervals[i][0];
            last[i] = intervals[i][1];
        }
        
        
        sort(start.begin() , start.end());
        sort(last.begin() , last.end());
        
        int rooms = 1 , result = 1;
        
        int i = 1 , j = 0;
        
        while(i < n && j < n){
            if(start[i] < last[j]){
                rooms++;
                i++;
            }
            
            else if(start[i] >= last[j]){
                rooms--;
                j++;
            }
            if(rooms > result){
                result = rooms;
            }
        }
        
        return result;
    }
};