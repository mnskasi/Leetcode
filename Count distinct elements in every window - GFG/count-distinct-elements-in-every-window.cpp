// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int> m;
        int r=0;
        int distinct=0;
        vector<int> ans;
        for (int i=0;i<k;i++)
        {
            if (m.find(A[i])!=m.end())
            {
                if (m[A[i]]==0)
                {
                    distinct++;
                }
                m[A[i]]++;
            }
            else
            {
               m[A[i]]=1;
               distinct++;
            }
        }
        for (int i=k;i<n;i++)
        {
            ans.push_back(distinct);
            m[A[r]]--;
            if (m[A[r]]==0)
            {
                distinct--;
            }
            r++;
            if (m.find(A[i])!=m.end())
            {
                if (m[A[i]]==0)
                {
                    distinct++;
                }
                m[A[i]]++;
            }
            else
            {
               m[A[i]]=1;
               distinct++;
            }
        }
        ans.push_back(distinct);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends