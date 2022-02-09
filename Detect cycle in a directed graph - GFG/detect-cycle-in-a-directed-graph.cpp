// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool check_cycle(int V, vector<int> adj[],int visited[],int dfsvisited[],int ind)
  {
      visited[ind]=1;
          for (auto i:adj[ind])
          {
              if (dfsvisited[i])
              {
                  return true;
              }
              else if(visited[i]==0)
              {
                  dfsvisited[i]=1;
                  if (check_cycle(V,adj,visited,dfsvisited,i)) 
                  {
                      return true;
                  }
                  dfsvisited[i]=0;
              }
          }
      return false;
      
  }
    // Function to detect cycle in a directed graph.
     bool isCyclic(int V, vector<int> adj[]) 
    {
        int visited[V]={0};
        int dfsvisited[V]={0};
        // code here
        for (int i=0;i<V;i++)
        {
            if (!visited[i])
            {
                dfsvisited[i]=1;
                if (check_cycle(V,adj,visited,dfsvisited,i)) return true;
                dfsvisited[i]=0;
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends