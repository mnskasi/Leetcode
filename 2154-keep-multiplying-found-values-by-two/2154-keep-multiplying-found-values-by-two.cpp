class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        int flag=0;
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++)
        {
            if (flag==0)
            {
                if (nums[i]%original==0)
                flag=1;
            }
            if (flag==1)
            {
                if (nums[i]%original==0)
                {
                    int temp=nums[i]/original;
                    int mark=0;
                    int temp1=temp;
                    while (temp>=2)
                    {
                        if (temp%2) 
                        {
                            mark=1;
                            break;
                        }
                        temp/=2;
                    }
                    if (mark==0 )
                    {
                        m[temp1]=1;
                    }
                }
            }
        }
        if (flag==0)
            return original;
            int ind=1;
            for (int i=0;i<m.size();i++)
            {
                if (m.find(ind)==m.end())
                {
                    break;
                }
                else
                {
                    ind*=2;
                }
            }
        return ind*original;
    }
};