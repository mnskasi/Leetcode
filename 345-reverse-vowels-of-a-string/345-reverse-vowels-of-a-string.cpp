class Solution {
public:
    string reverseVowels(string s) 
    {
        int l=-1;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
            {
                l=i;
                break;
            }
        }
        if (l==-1) return s;
        int h=-1;
        for (int i=s.size()-1;i>=0;i--)
        {
            if (s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
            {
                h=i;
                break;
            }
        }
        while(l<h)
        {
            char temp=s[l];
            s[l]=s[h];
            s[h]=temp;
            for (int i=l+1;i<s.size();i++)
            {
                if (s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
                {
                    l=i;
                    break;
                }
            }
            for (int i=h-1;i>=0;i--)
            {
                if (s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
                {
                    h=i;
                    break;
                }
            }
        }
        return s;
    }
};