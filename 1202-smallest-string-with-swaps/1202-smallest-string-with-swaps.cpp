class Solution {
public:
      void dfs(int node,vector<int>&trav,vector<vector<int>>&a,vector<int>&vis )
    {
        vis[node]=1;
        trav.push_back(node);
        for(auto x:a[node])
        {
            if(!vis[x])
                dfs(x,trav,a,vis);
        }
    }
    public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
        int c=0,n=s.size();
        vector<int> vis(n,0);
        vector<vector<int>> graph(n);
        for(auto x:p)
        {
            int i=x[0],j=x[1];
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
        vector<int> traversal; // to store current connected component
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&graph[i].size())
            {
                dfs(i,traversal,graph,vis);
                string t;
                sort(traversal.begin(),traversal.end());
                for(auto x:traversal)
                    t+=s[x];
                sort(t.begin(),t.end());
                int k=0;
                for(auto x:traversal)
                    s[x]=t[k++];    
                traversal.clear();
            }    
        }
        return s;
    }
};