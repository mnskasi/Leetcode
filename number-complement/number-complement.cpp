class Solution {
public:
    int findComplement(int num) 
    {
        int index=0;
        int res=0;
        while (num > 0)
        {
            if (num%2==0)
            {
                res+=pow(2,index);
            }
            num=num/2;
            index++;
        }
        return res;
    }
};