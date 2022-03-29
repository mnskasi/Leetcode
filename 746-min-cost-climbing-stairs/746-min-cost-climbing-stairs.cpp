class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int prev1=cost[1];
        int prev2=cost[0];
        for (int i=2;i<cost.size();i++)
        {
            int act=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=act;
        }
        return min(prev1,prev2);
    }
};