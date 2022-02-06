class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        vector<int>odd;
        vector<int> even;
        for (int i=0;i<nums.size();i++)
        {
            if (i%2)
            {
                odd.push_back(nums[i]);
            }
            else
            {
                even.push_back(nums[i]);
            }
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        int o=0;
        int e=0;
        vector<int> res;
        for (int i=0;i<nums.size();i++)
        {
            if (i%2)
            {
                res.push_back(odd[o]);
                o++;
            }
            else
            {
                res.push_back(even[e]);
                e++;
            }
        }
        return res;
    }
};