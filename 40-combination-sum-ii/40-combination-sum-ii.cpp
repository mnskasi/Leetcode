class Solution 
{
public:
    void solve (vector< vector<int> > &res,vector<int> op, vector<int> candidates,int target)
    {
        if (target==0)
            {
                res.push_back(op);
                return;
            }
            
        if (candidates.size()==0)
        {
            return;
        }
        int top=candidates[candidates.size()-1];
        if (top <= target)
        {
            candidates.pop_back();
            op.push_back(top);
            solve(res,op,candidates,target-top);
            if (candidates.size()==0) return;
            while(top==candidates[candidates.size()-1] )
            {
                candidates.pop_back();
                if (candidates.size()==0) return;
            }
            op.pop_back();
            solve(res,op,candidates,target);
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int> > res;
        vector<int> op;
        sort(candidates.begin(),candidates.end(),greater<int>());
        solve(res,op,candidates,target);
        return res;
    }
};