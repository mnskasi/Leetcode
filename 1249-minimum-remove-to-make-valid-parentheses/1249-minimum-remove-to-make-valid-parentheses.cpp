class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> st;
        unordered_map<int,int> m;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
            {
                st.push(i);
                
            }
            else if (s[i]==')')
            {
                if (st.size()==0)
                {
                    m[i]=1;
                }
                else
                {
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            m[st.top()]=1;
            st.pop();
        }
        string res="";
        for (int i=0;i<s.size();i++)
        {
            if (m.find(i)==m.end())
            {
                res+=s[i];
            }
        }
        return res;
    }
    
};