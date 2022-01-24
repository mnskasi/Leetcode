// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool possible (bool graph[101][101], int m, int n,int ind,int color[])
{
    for (int i=0;i<n;i++)
    {
        if (graph[ind][i]==1 && color[i]==color[ind] && i!=ind)
        {
            return false;
        }
    }
    return true;
    
}

bool solve (bool graph[101][101], int m, int n,int ind,int color[])
{
    if (ind==n)
    {
        return true;
    }
    for (int i=1;i<=m;i++)
    {
        color[ind]=i;
        if (possible(graph,m,n,ind,color))
        {
            if (solve(graph,m,n,ind+1,color))
            {
                return true;
            }
            else
            {
                color[ind]=0;
            }
        }
        else
        {
            color[ind]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    if (m==1 )
    {
        if (V==1)
        {
            return true;
        }
        return false;
    }
    // your code here
    int color[V];
    for (int i=0;i<V;i++)
    {
        color[i]=0;
    }
    return solve(graph,m,V,0,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends