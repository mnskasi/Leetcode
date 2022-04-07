class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        vector<int> flag (stones.size(),0);
        int cnt=stones.size();
        int mx1=0;
        int mx2=0;
        while (true)
        {
            int i1 = 0;
            int i2 = 0;
            for (int i=0; i<stones.size();i++)
            {
                if (stones[i] >= mx1)
                {
                    mx2=mx1;
                    i2=i1;
                    mx1=stones[i];
                    i1=i;
                }
                else if (stones[i] >= mx2)
                {
                    mx2=stones[i];
                    i2=i;
                }
            }
            if (mx1==0 or mx2==0)
            {
                break;
            }
            else
            {
                if (mx1==mx2)
                {
                    stones[i1]=0;
                    stones[i2]=0;
                }
                else
                {
                    stones[i2] = 0;
                    stones[i1] = mx1-mx2;
                }
            }
            mx1=0;
            mx2=0;
        }
        return max(mx1,mx2);
        
        
    }
};