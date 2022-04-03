class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.size()<2) return;
        int l1=nums[nums.size()-1];
        int l2=nums[nums.size()-2];
        if (l1 > l2)
        {
            int temp=nums[nums.size()-1];
            nums[nums.size()-1]=nums[nums.size()-2];
            nums[nums.size()-2]=temp;
            return;
        }
        int flag=-1;
        for (int i=nums.size()-2;i>=0;i--)
        {
            if (nums[i] < nums[i+1])
            {
                flag=i;
                break;
            }
        }
        if (flag==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        reverse(nums.begin()+flag+1,nums.end());
        for (int i=flag+1;i<nums.size();i++)
        {
            if (nums[i] > nums[flag])
            {
                int temp=nums[flag];
                nums[flag]=nums[i];
                nums[i]=temp;
                return;
            }
        }
        return;
    }
};