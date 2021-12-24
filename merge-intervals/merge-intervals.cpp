class Solution {
public:
    bool comparator (vector<int>a,vector<int>b)
    {
        return (a[0] < b[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector < int> flag (intervals.size(),0);
        sort(intervals.begin(),intervals.end());
        for (int i=1;i<intervals.size();i++)
        {
            if (intervals[i][0]<=intervals[i-1][1])
            {
                intervals[i][0]=intervals[i-1][0];
                if (intervals[i-1][1] > intervals[i][1])
                {
                    intervals[i][1]=intervals[i-1][1];
                }
                flag[i-1]=1;
            }
        }
        vector< vector <int> > res;
        for (int i=0;i<intervals.size();i++)
        {
            if (flag[i]==0)
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};