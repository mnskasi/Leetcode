class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int flag=0;
        for (int i=1;i<arr.size();i++)
        {
            if (flag==0)
            {
                if (arr[i]<=arr[i-1])
                {
                    return false;
                }
                else
                {
                    flag=1;
                    continue;
                }
            }
            if (flag==1)
            {
                if (arr[i]<arr[i-1])
                {
                    flag=2;
                    continue;
                }
                else if (arr[i]==arr[i-1])
                {
                    return false;
                }
            }
            if (flag==2)
            {
                if (arr[i]>=arr[i-1])
                {
                    return false;
                }
            }
        }
        if (flag==2)
        {
            return true;
        }
        return false;
    }
};