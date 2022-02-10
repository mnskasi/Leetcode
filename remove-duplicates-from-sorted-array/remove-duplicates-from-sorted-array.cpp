class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int ind=1;
        int n=nums.size();
        int cnt=1;
        int i;
        int sz=nums.size();
        for (i=1;i<sz;i++)
        {
            if (nums[i-1]!=nums[i])
            {
                if (ind==i)
                {
                    ind++;
                }
                else
                {
                    int temp=ind;
                    for (int j=i;j<nums.size();j++)
                    {
                        nums[temp]=nums[j];
                        temp++;
                    }
                    sz=temp;
                    i=ind;
                    ind++;
                }
            }
            cnt++;
            if (cnt==nums.size()) break;
        }
        // cout<<"ind is "<<ind<<" i is "<<i<<"cnt is "<<cnt<<" sz is "<<sz<<endl;
        return ind;
    }
};