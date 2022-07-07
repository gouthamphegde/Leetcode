class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    
            int nRow = s1.size();
        int nCol = s2.size();
        if(s1.size() + s2.size() != s3.size())
            return false;
        bool reachable[nRow+1][nCol+1];
        reachable[0][0] = true;
        for(int col=1; col<=nCol; col++)
        {
            if(s3[col-1] == s2[col-1])
                reachable[0][col] = true;
            else
            {
                for(;col<=nCol; col++)
                    reachable[0][col] = false;
                break;
            }
        }
        for(int row=1; row<=nRow; row++)
        {
            if(s3[row-1] == s1[row-1])
                reachable[row][0] = true;
            else
            {
                for(;row<=nRow; row++)
                    reachable[row][0] = false;
                break;
            }
        }
        for(int row=1; row<=nRow; row++)
        {
            for(int col=1; col<=nCol; col++)
            {
                // reachable from the left:
                if(reachable[row][col-1] && s3[row+col-1] == s2[col-1])
                    reachable[row][col] = true;
				// reachable from the top
                else if(reachable[row-1][col] && s3[row+col-1] == s1[row-1])
                    reachable[row][col] = true;
                else
				// unreachable
                    reachable[row][col] = false;
            }
        }
        return reachable[nRow][nCol];
    }
};
