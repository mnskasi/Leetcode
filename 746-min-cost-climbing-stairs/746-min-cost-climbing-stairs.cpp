class Solution {
public:
    int solve(vector<int> &cost,unordered_map<int,int> &m,int i)
    {
        if (i==0 or i==1) return cost[i];
        if (i==cost.size())
        {
            return min(solve(cost,m,i-1),solve(cost,m,i-2));
        }
        if (m.find(i)!=m.end())
        {
            return m[i];
        }
        else
        {
            m[i]=cost[i]+min(solve(cost,m,i-1),solve(cost,m,i-2));
            return m[i];
        }
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        unordered_map<int,int> m;
        return solve(cost,m,cost.size());
    }
};