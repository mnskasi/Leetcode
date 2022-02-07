class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map <char,int> m1;
        unordered_map <char,int> m2;
        for (int i=0;i<s.size();i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        m2[t[s.size()]]++;
        for (auto i:m2)
        {
            if (m1.find(i.first)==m1.end())
            {
                return i.first;
            }
            else if (m1[i.first] < i.second)
            {
                return i.first;
            }
        }
        return 'a';
    }
};