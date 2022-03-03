class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int arr[cost.size()+1];
        arr[0]=cost[0];
        arr[1]=cost[1];
        for (int i=2;i<cost.size();i++)
        {
            arr[i]=cost[i]+min(arr[i-1],arr[i-2]);
        }
        return min(arr[cost.size()-1],arr[cost.size()-2]);
    }
};