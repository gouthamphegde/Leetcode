class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if( k >= m + n - 3 ) // optimisation
            return m + n - 2;
        
        queue<vector<int>> q;
        q.push({0, 0, k, 0});
        vector<vector<int>> bestHeight(m, vector<int>(n, -1));
        bestHeight[0][0] = k;
        while(!q.empty())
        {
            auto v = q.front();
            q.pop();
            int x = v[0];
            int y = v[1];
            int nElimLeft = v[2];
            int nSteps = v[3];
            
            if(nElimLeft < bestHeight[x][y])  // optimisation
                continue;
            
            if(x == m-1 && y == n-1)
                return nSteps;
            
            int steps[4][2] = {{x-1,y}, {x+1,y}, {x,y-1}, {x,y+1}};
            for(auto e : steps)
            {
                int x = e[0];
                int y = e[1];
                if( x>=0 && x<m && y>=0 && y<n )
                    // if inside the grid
                {
                    if(grid[x][y] && nElimLeft>0 && nElimLeft-1 > bestHeight[x][y])
                    {
                        q.push({x, y, nElimLeft-1, nSteps+1});
                        bestHeight[x][y] = nElimLeft-1;
                    }
                    else if(!grid[x][y] && nElimLeft > bestHeight[x][y])
                    {
                        q.push({x, y, nElimLeft, nSteps+1});
                        bestHeight[x][y] = nElimLeft;
                    }
                }
            }
 
        }
        return -1;
    }
};