class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int tcnt[7];
        int bcnt[7];
        for (int i=1;i<7;i++)
        {
            tcnt[i]=0;
            bcnt[i]=0;
        }
        for (int i=0;i<7;i++)
        {
            for (int j=0;j<tops.size();j++)
            {
                if (tops[j]==i and bottoms[j]==i)
                {
                    continue;
                }
                else if (tops[j]==i)
                {
                    bcnt[i]++;
                }
                else if (bottoms[j]==i)
                {
                    tcnt[i]++;
                }                
                else
                {
                    tcnt[i]=-1;
                    bcnt[i]=-1;
                    break;
                }
            }
        }
        int flag=0;
        int res=INT_MAX;
        for (int i=1;i<7;i++)
        {
            if (tcnt[i]!=-1 and tcnt[i]< res)
            {
                flag=1;
                res=tcnt[i];
            }
            if (bcnt[i]!=-1 and bcnt[i]< res)
            {
                flag=1;
                res=bcnt[i];
            }
        }
        if (flag==0)
        {
            return -1;
        }
        else
        {
            return res;
        }
    }
};