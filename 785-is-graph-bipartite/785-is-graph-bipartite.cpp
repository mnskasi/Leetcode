class Solution 
{
public:
    bool checkbipartite (vector<vector<int>>& graph,int visited[],int colour[],int ind)
    {
        visited[ind]=1;
            for (auto i:graph[ind])
            {
                if (visited[i]==1 )
                {
                    if (colour[i]==colour[ind])
                    return false;
                }
                else
                {
                    if (colour[ind]==0)
                    {
                        colour[i]=1;
                    }
                    else
                    {
                        colour[i]=0;
                    }
                    if (!checkbipartite(graph,visited,colour,i)) return false;
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