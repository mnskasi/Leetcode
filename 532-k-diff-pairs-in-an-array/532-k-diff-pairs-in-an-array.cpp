class Solution 
{
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        for (auto i:nums)
        {
            m[i]++;
        }
        int sum=0;
        if (k==0)
        {
            for (auto i:m)
            {
                if(i.second>1)
                {
                    sum++;
                }
            }
            return sum;
        }
        for (auto i:m)
        {
            int temp1=i.first+k;
            int temp2=i.first-k;
            if (m.find(temp1)!=m.end())
            {
                sum++;
            }
            if (m.find(temp2)!=m.end())
            {
                sum++;
            }
        }
        return sum/2;
    }
};