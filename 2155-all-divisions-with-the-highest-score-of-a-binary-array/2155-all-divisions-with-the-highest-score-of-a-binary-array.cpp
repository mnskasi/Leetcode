class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) 
    {
        int zcount=0;
        int ocount=0;
        for (auto i: nums)
        {
            if (i==0)
            {
                zcount++;
            }
            else
            {
                ocount++;
            }
        }
        vector<int> res;
        int lz=0;
        int ro=ocount;
        int max=0;
        for (int i=0;i<nums.size();i++)
        {
            int sum=lz+ro;
            if (sum > max)
            {
                vector<int> temp;
                temp.push_back(i);
                res=temp;
                max=sum;
            }
            else if(sum==max)
            {
                res.push_back(i);
            }
            if (nums[i]==0)
            {
                lz++;
            }
            else
            {
                ro--;
            }
        }
        int sum=lz+ro;
            if (sum > max)
            {
                vector<int> temp;
                temp.push_back(nums.size());
                res=temp;
                max=sum;
            }
            else if(sum==max)
            {
                res.push_back(nums.size());
            }
        return res;
    }
};