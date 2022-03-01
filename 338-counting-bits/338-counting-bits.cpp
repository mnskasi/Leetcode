class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> res;
        for (int i=0;i<=n;i++)
        {
            int temp=i;
            int cnt=0;
            while(temp > 0)
            {
                if (temp%2) cnt++;
                temp/=2;
            }
            res.push_back(cnt);
        }
        return res;
    }
};