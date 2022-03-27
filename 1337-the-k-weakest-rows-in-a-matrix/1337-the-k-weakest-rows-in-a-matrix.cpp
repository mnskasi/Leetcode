class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>> res;
        int ind=0;
        for (auto i: mat)
        {
            int cnt=0;
            for (auto j:i)
            {
                if (j==1)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            res.push_back(make_pair(cnt,ind));
            ind++;
        }
        sort(res.begin(),res.end());
        vector<int> ans;
        for (int i=0;i<k;i++)
        {
            ans.push_back(res[i].second);
        }
        return ans;
    }
};