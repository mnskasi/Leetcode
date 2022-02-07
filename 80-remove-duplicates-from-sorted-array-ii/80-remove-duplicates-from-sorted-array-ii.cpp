class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int cnt=1;
        int k=0;
        for (int i=1;i<nums.size()-k;i++)
        {
            if (nums[i]!=nums[i-1])
            {
                if (cnt > 2)
                {
                    k+=cnt-2;
                    int ind=i-(cnt-2);
                    for (int j=i;j<nums.size();j++)
                    {
                        nums[ind++]=nums[j];
                    }
                    i=i-(cnt-2);
                }
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt > 2)
                {
            int i=nums.size()-1;
                    k+=cnt-2;
                    int ind=i-(cnt-2);
                    for (int j=i;j<nums.size();j++)
                    {
                        nums[ind++]=nums[j];
                    }
                    i=i-(cnt-2);
                }
        return nums.size()-k;
    }
};