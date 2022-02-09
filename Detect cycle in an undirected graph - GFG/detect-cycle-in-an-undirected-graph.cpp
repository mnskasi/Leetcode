// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
  bool check_cycle(int V, vector<int> adj[],int visited[],int ind,int parent)
  {
      queue<int> q;
      queue<int> p;
      p.push(parent);
      q.push(ind);
      visited[ind]=1;
      while(q.size()!=0)
      {
          
          int par=p.front();
          p.pop();
          int node=q.front();
          q.front();
          q.pop();
        //   cout<<"in queue "<<node<<endl;
          for (auto i:adj[node])
          {
              if (visited[i])
              {
                  if ( i!=par)
                  return true;
              }
              else
              {
                  q.push(i);
                  p.push(node);
                  visited[i]=1;
              }
          }
      }
      return false;
      
  }
    // Function to detect cycle in a directed graph.
     bool isCycle(int V, vector<int> adj[]) 
    {
        int visited[V]={0};
        // code here
        for (int i=0;i<V;i++)
        {
            if (!visited[i])
            {
                if (check_cycle(V,adj,visited,i,-1)) return true;
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends