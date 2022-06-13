class Solution {
public:
    int f(int i , int j , vector<vector<int>> & triangle,vector<vector<int>> &dp){
        if(j > dp[0].size() - 1){
            return 1e9;
        }
        if(i == triangle.size() - 1){
            return triangle[i][j];
        }
        
        if(dp[i][j]!=-1e9){
            return dp[i][j];
        }
        
        int down = triangle[i][j]+f(i+1,j,triangle,dp);
        int left = triangle[i][j]+f(i+1,j+1,triangle,dp);
        
        return dp[i][j] = min(down,left);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //fixed start and variable ending
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1e9));
                               
        return f(0,0,triangle,dp);
                               

        
        
        
    }
};