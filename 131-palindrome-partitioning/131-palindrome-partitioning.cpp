class Solution {
public:
    bool ispalindrome(string s,int start,int end)
    {
        // for (int k=ind;k<ind+(i-ind+1)/2;k++)
        // {
        //     if (s[k]!=s[i-k-ind])
        //     {
        //         return false;
        //     }
        // }
        // return true;
        while (start<=end)
        {
            if (s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(string s,vector<vector<string> > &res,int ind,vector<string> path)
    {
        int n=s.size();
        if (ind==n)
        {
            res.push_back(path);
            return;
        }
        for (int i=ind;i<n;i++)
        {
            if (ispalindrome(s,ind,i))
            {
                path.push_back(s.substr(ind,i-ind+1));
                solve(s,res,i+1,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string> > res;
        vector<string> path;
        solve(s,res,0,path);
        return res;
    }
};