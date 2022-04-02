class Solution {
public:
    bool check1palindrome(string s)
    {
        int flag=0;
        int j=s.size()-1;
        for (int i=0;i<=(s.size()-1)/2;i++)
        {
            if (s[i]!=s[j])
            {
                if (flag==0)
                {
                    flag=1;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        bool temp=check1palindrome(s);
        if (temp==true)
        {
            return true;
        }
        else
        {
            reverse(s.begin(),s.end());
            return check1palindrome(s);
        }
    }
};