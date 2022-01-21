class Solution {
public:
    void solve(vector< vector<string> > &res,vector<string> arr,int ind,int n,vector<int>row, vector<int>up, vector<int>down)
    {
        if (ind==n)
        {
            res.push_back(arr);
            return;
        }
        for (int i=0;i<n;i++)
        {
            if (row[i]==0 && up[i+ind]==0 && down[n-1+ind-i]==0)
            {
                arr[i][ind]='Q';
                row[i]=1;
                up[i+ind]=1;
                down[n-1+ind-i]=1;
                solve(res,arr,ind+1,n,row,up,down);
                arr[i][ind]='.';
                row[i]=0;
                up[i+ind]=0;
                down[n-1+ind-i]=0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector< vector<string> > res ;
        vector<string> arr(n,string(n,'.'));
        solve(res,arr,0,n,vector<int>(n,0),vector<int>(2*n-1,0),vector<int>(2*n-1,0));
        return res;
    }
};