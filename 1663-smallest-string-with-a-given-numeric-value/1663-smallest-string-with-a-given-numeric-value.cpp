class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string res="";
        for (int i=0;i<n;i++)
        {
            res+='a';
        }
        if (n==k)
        {
            return res;
        }
        else
        {
            int temp=k-n;
            int ind=n-1;
            while(temp>0)
            {
                if (temp<=25)
                {
                    res[ind]+=temp;
                    temp=0;
                }
                else
                {
                    res[ind]='z';
                    temp-=25;
                }
                ind--;
            }
        }
        return res;
    }
};