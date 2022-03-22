// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[],int ind,int n,int amount, vector<vector<int> > &dp)
    {
        if (amount==0) return 0;
        if (ind==n) return 0;
        if (dp[ind][amount]==-1)
        {
            int consider=0;
            if (amount>ind)
                consider=price[ind]+solve(price,ind,n,amount-(ind+1),dp);
            int notConsider=solve(price,ind+1,n,amount,dp);
            dp[ind][amount]= max(consider,notConsider);
        }
        return dp[ind][amount];
    }
    int cutRod(int price[], int n) 
    {
        //code here
        vector<vector<int> > dp (n,vector<int> (n+1,-1));
        return solve(price,0,n,n,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends