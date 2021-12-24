class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set <vector <int> > res;
        vector<int> op;
        solve(nums,op,res);
        vector < vector < int> > ans;
        copy(res.begin(),res.end(),back_inserter(ans));
        return ans;
    }
    void solve (vector<int> ip,vector <int> op,set<vector<int>> &res)
    {
        if (ip.size()==0)
        {
            res.insert(op);
            return;
        }
        vector <int> op1 =op;
        vector <int> op2 =op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1,res);
        solve(ip,op2,res);
    }
};