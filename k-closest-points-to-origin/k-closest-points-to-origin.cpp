class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<pair<int,int> > m;
        for (int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            m.push_back(make_pair(x*x+y*y,i));
        }
        sort(m.begin(),m.end());
        vector<vector<int> > res;
        for (int i=0;i<k;i++)
        {
            vector<int> temp;
            int index=m[i].second;
            temp.push_back(points[index][0]);
            temp.push_back(points[index][1]);
            res.push_back(temp);
        }
        return res;
    }
};