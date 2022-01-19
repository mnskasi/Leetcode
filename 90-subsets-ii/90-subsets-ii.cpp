class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector <vector <int> > res;
        vector<int> op;
        solve(nums,op,res);
        // vector < vector < int> > ans;
        // copy(res.begin(),res.end(),back_inserter(ans));
        return res;
    }
    void solve (vector<int> ip,vector <int> op,vector<vector<int> > &res)
    {
        if (ip.size()==0)
        {
            res.push_back(op);
            return;
        }
        vector <int> op1 =op;
        vector <int> op2 =op;
        int top=ip[ip.size()-1];
        op2.push_back(top);
        ip.pop_back();
        solve(ip,op2,res);
        while(ip.size()>0 && ip[ip.size()-1]==top)
        {
            ip.pop_back();
        }
        solve(ip,op1,res);
    }
};