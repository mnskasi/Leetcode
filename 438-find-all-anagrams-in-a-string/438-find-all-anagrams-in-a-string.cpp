class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> res;
        vector<int> ch (26,0);
        for (int i=0;i<p.size();i++)
        {
            ch[p[i]-'a']++;
        }
        if (p.size() > s.size())
        {
            return res;
        }
        vector<int> temp(26,0);
        for (int i=0;i<p.size()-1;i++)
        {
            temp[s[i]-'a']++;
        }
        for (int i=0;i<s.size();i++)
        {
            if (i+p.size() > s.size())
            {
                break;
            }
            temp[s[i+p.size()-1]-'a']++;
            if (temp==ch)
            {
                res.push_back(i);
            }
            temp[s[i]-'a']--;
        }
        return res;
    }
};