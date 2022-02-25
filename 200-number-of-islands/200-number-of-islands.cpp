class Solution {
public:
    void solve(vector<vector<int> >&visited, vector<vector<char>>& grid, int n, int m ,int i, int j)
    {
        if (i<0 or i>=n) return;
        if (j<0 or j>=m) return;
        if (i!=0 && grid[i-1][j]=='1' && visited[i-1][j]==0)
        {
            visited[i-1][j]=1;
            solve(visited,grid,grid.size(),grid[0].size(),i-1,j);
        }
        if (i!=n-1 && grid[i+1][j]=='1' && visited[i+1][j]==0)
        {
            visited[i+1][j]=1;
            solve(visited,grid,grid.size(),grid[0].size(),i+1,j);
        }
        if (j!=0 && grid[i][j-1]=='1' && visited[i][j-1]==0)
        {
            visited[i][j-1]=1;
            solve(visited,grid,grid.size(),grid[0].size(),i,j-1);
        }
        if (j!=m-1 && grid[i][j+1]=='1' && visited[i][j+1]==0)
        {
            visited[i][j+1]=1;
            solve(visited,grid,grid.size(),grid[0].size(),i,j+1);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<vector<int> >visited (grid.size(),vector<int> (grid[0].size(),0));
        int cnt=0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if (visited[i][j]==0 && grid[i][j]=='1')
                {
                    visited[i][j]=1;
                    solve(visited,grid,grid.size(),grid[0].size(),i,j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};