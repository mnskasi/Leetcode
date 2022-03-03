class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int res=0;
        if (nums.size()<3) return 0;
        int cnt=2;
        int cd=nums[1]-nums[0];
        for (int i=2;i<nums.size();i++)
        {
            if ((nums[i]-nums[i-1])!=cd)
            {
                if (cnt>=3)
                {
                    int temp=(cnt-2)*(cnt-1);
                    temp/=2;
                    res+=temp;
                }
                cnt=2;
                cd=nums[i]-nums[i-1];
            }
            else
            {
                cnt++;
            }
        }
        if (cnt>=3)
        {
            int temp=(cnt-2)*(cnt-1);
            temp/=2;
            res+=temp;
        }
        return res;
    }
};