// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++


class Solution{
    public:
    void solve(vector< vector <int> > m,vector<string> & res,string path,int n, int i,int j)
    {
        if (i==n-1 && j==n-1)
        {
            res.push_back(path);
            return ;
        }
        if (i!=n-1 && m[i+1][j]!=0)
        {
            path+="D";
            m[i][j]=0;
            solve(m,res,path,n,i+1,j);
            m[i][j]=1;
            path.pop_back();
        }
        if (j!=0 && m[i][j-1]!=0)
        {
            path+="L";
            m[i][j]=0;
            solve(m,res,path,n,i,j-1);
            m[i][j]=1;
            path.pop_back();
        }
        if (j!=n-1 && m[i][j+1]!=0)
        {
            path+="R";
            m[i][j]=0;
            solve(m,res,path,n,i,j+1);
            m[i][j]=1;
            path.pop_back();
        }
        if (i!=0 && m[i-1][j]!=0)
        {
            path+="U";
            m[i][j]=0;
            solve(m,res,path,n,i-1,j);
            m[i][j]=1;
            path.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> res;
        string path="";
        if (m[n-1][n-1]==0 || m[0][0]==0)
        {
            return res;
        }
        solve(m,res,path,n,0,0);
        return res;
        // Your code goes here
    }
};
    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends