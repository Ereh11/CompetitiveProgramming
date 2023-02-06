class Solution {
public:
    int n, m;
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    bool b = 1;
    bool check(int r, int c) { return(r >= 0 && r < n && c >= 0 && c < m); }
    void DFS(int r, int c, vector<vector<int>>& grid)
    {   
        grid[r][c] = 1;
        if(!r || r == n - 1 || !c || c == m - 1) b = 0;
        for(int i = 0; i < 4; i++)
        {
            int x = r + dx[i], y = c + dy[i];
            if(check(x, y) && !grid[x][y]) DFS(x, y, grid);
        }
        
    }
    int closedIsland(vector<vector<int>>& grid)
    {
       int ans= 0;
       n = grid.size(), m = grid[0].size();
       
       for(int i = 0; i < n ; i++)
           for(int j = 0; j < m ; j++) 
               if(!grid[i][j])
               {
                   DFS(i, j, grid);
                   ans +=(b == 1);
                   b = 1;
               }
        
       return ans; 
    }
};
