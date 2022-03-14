class Solution {
public:
    string simplifyPath(string path) 
    {
        vector<string> res;
        string temp="";
        for (int i=1;i<path.size();i++)
        {
            if (path[i]=='/')
            {
                if (temp==".")
                {
                    temp="";
                    continue;
                }
                else if (temp=="..")
                {
                    if (res.size()!=0)
                    {                    
                        res.pop_back();
                    }
                    temp="";
                }
                else
                {
                    if (temp!="")
                    {
                        res.push_back(temp);
                    }
                    temp="";
                }
            }
            else
            {
                temp.push_back(path[i]);
            }
        }
        if (temp!="")
        {
            if (temp=="..")
            {
                if (res.size()!=0)
                {                    
                    res.pop_back();
                }
                temp="";
            }
            else
            {
                if (temp!="" and temp!=".")
                {
                    res.push_back(temp);
                }
                temp="";
            }
        }
        if (res.size()==0)
        {
            string ans="/";
            return ans;
        }
        string ans="";
        for (int i=0;i<res.size();i++)
        {
            ans+="/";
            ans+=res[i];
        }
        return ans;
    }
};