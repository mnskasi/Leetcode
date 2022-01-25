// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ifexist(string temp,vector<string> &dictionary)
    {
        for (auto i:dictionary)
        {
            if (i==temp)
            {
                return true;
            }
        }
        return false;
    }
    void solve(vector<string> &res,string s,string ans,vector<string> &dictionary,int n,int ind)
    {
        if (ind==n)
        {
            res.push_back(ans);
            return;
        }
        for (int i=ind;i<n;i++)
        {
            string temp=s.substr(ind,i-ind+1);
            if (ifexist(temp,dictionary))
            {
                if (i!=n-1)
                {
                    temp+=" ";
                }
                solve(res,s,ans+temp,dictionary,n,i+1);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> res;
        string ans="";
        solve(res,s,ans,dict,s.size(),0);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends