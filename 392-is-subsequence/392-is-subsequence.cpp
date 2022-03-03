class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if (s.size()==0 && t.size()==0) return true;
        if (t.size() < s.size()) return false;
        int t1=0;
        for (int i=0;i<t.size();i++)
        {
            if (t[i]==s[t1])
            {
                t1++;
            }
            if (s.size()==t1)
            {
                return true;
            }
        }
        return false;
    }
};