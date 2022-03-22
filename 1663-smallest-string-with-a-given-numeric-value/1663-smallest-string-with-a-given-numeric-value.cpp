class Solution {
public:
    string getSmallestString(int n, int k) {
        int t=n; 
        string s="";
        for(int i=0;i<n;i++)
        {
            if(t>1)
            {
                if(((t-1)*26)>=k)
                {
                    s+="a";
                    t--;
                    k--;
                }
                else
                {
                    s += 'a' + (k-((t-1)*26))-1;
                    t--;
                    k=t*26;
                }
            }
            else 
                s+='a' + k -1;
        }
    return s;
    }
};