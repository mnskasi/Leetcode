class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        int prev=0;
        vector<vector<int> > res;
        for (int i=0;i<numRows;i++)
        {
            vector<int> temp;
            if (i==0)
            {
                temp.push_back(1);
                res.push_back(temp);
                continue;
            }
            temp.push_back(1);
            for (int j=1;j<i;j++)
            {
                temp.push_back(res[res.size()-1][j-1]+res[res.size()-1][j]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};