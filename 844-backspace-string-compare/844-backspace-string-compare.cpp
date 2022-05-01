class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string s1 = "";
        string s2 = "";
        for (auto i:s)
        {
            if (i == '#')
            {
                if (s1.size()!= 0)
                    s1.pop_back();
            }
            else
            {
                s1 += i;
            }
        }
        for (auto i:t)
        {
            if (i == '#')
            {
                if (s2.size()!= 0)
                    s2.pop_back();
            }
            else
            {
                s2 += i;
            }
        }
        if (s1 == s2) return true;
        return false;
    }
};