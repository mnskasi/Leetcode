class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        for (auto i: nums)
        {
            m[i]++;
        }
        vector< pair<int,int> > arr;
        for (auto i: m)
        {
            arr.push_back(make_pair(i.second,i.first));
        }
        sort(arr.begin(),arr.end());
        int ind=0;
        vector<int> res;
        for (int i=arr.size()-1;i>=0;i--)
        {
            if (ind>=k) break;
            res.push_back(arr[i].second);
            ind++;
        }
        return res;
    }
};