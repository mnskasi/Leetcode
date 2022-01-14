class Solution {
public:
    void solve (vector< vector<int> > &res,vector<int> op, vector<int> candidates,int target)
    {
        if (candidates.size()==0)
        {
            if (target==0)
            {
                res.push_back(op);
            }
            return;
        }
        
        int top=candidates[candidates.size()-1];
        if (top <= target)
        {
            op.push_back(top);
            solve(res,op,candidates,target-top);
            op.pop_back();
        }
        
        candidates.pop_back();
        solve(res,op,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int> > res;
        vector<int> op;
        solve(res,op,candidates,target);
        return res;
    }
};