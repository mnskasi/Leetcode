class Solution {
public:
    int solve(int amount,int ind, vector<int> &coins,vector<vector<int> > &dp)
    {
        if (amount==0)
        {
            return 1;
        }
        if (ind==coins.size())
        {
            return 0;
        }
        if (dp[ind][amount]==-1)
        {
            int consider=0;
            if (amount>=coins[ind])
            {
                consider=solve(amount-coins[ind],ind,coins,dp);
            }
            int notConsider=solve(amount,ind+1,coins,dp);
            dp[ind][amount]= consider+notConsider;
        }
        return dp[ind][amount];
    }
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int> > dp(coins.size(),vector<int> (amount+1,-1));
        return solve(amount,0,coins,dp);
    }
};