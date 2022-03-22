class Solution {
public:
    int solve(int amount, vector<int> &coins, int ind, vector<vector<int> > &dp)
    {
        if (amount==0)
        {
            return 0;
        }
        if (ind==coins.size())
        {
            return INT_MAX;
        }
        else
        {
            if (dp[ind][amount]==-1)
            {
                int consider=INT_MAX;
                if (amount>=coins[ind])
                {
                    consider=solve(amount-coins[ind],coins,ind,dp);
                }

                int not_consider=solve(amount,coins,ind+1,dp);
                if (consider==INT_MAX) 
                {
                    dp[ind][amount]=not_consider;
                }
                else
                    dp[ind][amount]=min(1+consider,not_consider);
            }
            
            return dp[ind][amount];
        }
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector< vector<int> > dp(coins.size(),vector<int> (amount+1,-1));
        int res=solve(amount,coins,0,dp);
        if (res==INT_MAX)
        {
            return -1;
        }
        return res;
    }
};