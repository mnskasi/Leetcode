class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int>res;
        for (int i=1;i<=9;i++)
        {
            int sum=0;
            for (int j=i;j<=9;j++)
            {
                sum*=10;
                sum+=j;
                if (sum >= low && sum<=high)
                {
                    res.push_back(sum);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};