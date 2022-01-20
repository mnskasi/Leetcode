class Solution {
public:
    void solve(vector< vector <int> > &res,vector<int> op,vector<int> nums,int ind,map<int,int> m)
    {
        if (ind<nums.size())
        {
            ind++;
            for (auto i : nums)
            {
                if (m.find(i)==m.end())
                {
                    op.push_back(i);
                    m[i]=1;
                    solve(res,op,nums,ind,m);
                    op.pop_back();
                    m[i]=0;
                }
                else if (m[i]==0)
                {
                    op.push_back(i);
                    m[i]=1;
                    solve(res,op,nums,ind,m);
                    op.pop_back();
                    m[i]=0;
                }
            }
        }
        else
        {
            res.push_back(op);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector< vector <int> > res;
        vector<int>op;
        map<int,int>m;
        solve(res,op,nums,0,m);
        return res;
    }
};