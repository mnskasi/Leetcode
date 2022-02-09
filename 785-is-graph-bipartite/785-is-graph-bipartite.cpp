class Solution 
{
public:
    bool checkbipartite (vector<vector<int>>& graph,int visited[],int colour[],int ind)
    {
        queue<int> q;
        q.push(ind);
        visited[0]=1;
        colour[0]=1;
        while(q.size()!=0)
        {
            int node=q.front();
            int c=colour[node];
            q.pop();
            for (auto i:graph[node])
            {
                if (visited[i]==1 )
                {
                    if (colour[i]==c)
                    return false;
                }
                else
                {
                    q.push(i);
                    colour[i]=c+1;
                    visited[i]=1;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        int visited[n];
        int colour[n];
        for (int i=0;i<n;i++)
        {
            visited[i]=0;
            colour[i]=0;
        }
        for (int i=0;i<n;i++)
        {
            if (!visited[i])
            {
                if (!checkbipartite(graph,visited,colour,i)) return false;
            }
        }
        return true;
    }
};