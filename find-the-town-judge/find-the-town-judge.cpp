class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> in(n,0);
        vector <int> out(n,0);
        for (auto i:trust)
        {
            out[i[0]-1]++;
            in[i[1]-1]++;
        }
        for (int i=0;i<n;i++)
        {
            if(in[i]==n-1 && out[i]==0)
            {
                return i+1;
            }
        }
        return -1;
    }
};