// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int * arr,int n,int ind,int score[])
	{
	    
	    if (ind<0) return 0;
	    if (ind==0) return arr[0];
	    if (score[ind]!=-1)
	    {
	        return score[ind];
	    }
	    int consider=arr[ind]+solve(arr,n,ind-2,score);
	    int notConsider=solve(arr,n,ind-1,score);
	    score[ind]= max(consider,notConsider);
	    return score[ind];
	   //return max(consider,notConsider);
	}
	int findMaxSum(int *arr, int n) 
	{
	    // code here
	    int score[n];
	    for (int i=0;i<n;i++)
	    {
	        score[i]=-1;
	    }
	    int ans= solve(arr,n,n-1,score);
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends