class Solution {
public:
    int maximumSwap(int num) 
    {
        vector<int> digits;
        int n=num;
        int flag=0;
        int prev=-1;
        while(n > 0)
        {
            digits.push_back(n%10);
            if (prev > n%10)
            {
                flag=1;
            }
            prev=n%10;
            n/=10;
        }
        if (flag == 0)
            return num;
        else
        {
            int mx=0;
            for (int i=0;i<digits.size();i++)
            {
                for (int j=i+1;j < digits.size();j++)
                {
                    int ans = 0;
                    for (int k=0;k<digits.size();k++)
                    {
                        if (k==i)
                        {
                            ans+=digits[j]*pow(10,k);
                        }
                        else if (k==j)
                        {
                            ans+=digits[i]*pow(10,k);
                        }
                        else
                        {
                            ans+=digits[k]*pow(10,k);
                        }
                    }
                    mx=max(mx, ans);
                }
            }
            return mx;
        }
        
    }
};