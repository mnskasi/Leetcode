class Solution {
public:
    int calculate(string s) 
    {
        vector<int> num;
        vector<char> symbols;
        int last=0;
        string temp;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]!=' ')
            {
                temp.push_back(s[i]);
            }
        }
        s=temp;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='*' || s[i]=='/' || s[i]=='-' || s[i]=='+')
            {
                string str=s.substr(last,i-last);
                //cout<<str<<endl;
                num.push_back(stoi(str));
                if (symbols.size()!=0 && (symbols[symbols.size()-1]=='*' || symbols[symbols.size()-1]=='/'))
                {
                    int num1=num[num.size()-1];
                    num.pop_back();
                    int num2=num[num.size()-1];
                    num.pop_back();
                    int res;
                    if (symbols[symbols.size()-1]=='*')
                    {
                        res=num1*num2;
                    }
                    if (symbols[symbols.size()-1]=='/')
                    {
                        res=num2/num1;
                    }
                    num.push_back(res);
                    symbols.pop_back();
                }
                symbols.push_back(s[i]);
                last=i+1;
            }
            if (i==s.size()-1)
            {
                // cout<<last<<endl;
                string str=s.substr(last,i-last+1);
                // cout<<str<<endl;
                num.push_back(stoi(str));
                // cout<<str<<endl;
                if (symbols.size()!=0 && (symbols[symbols.size()-1]=='*' || symbols[symbols.size()-1]=='/'))
                {
                    int num1=num[num.size()-1];
                    num.pop_back();
                    int num2=num[num.size()-1];
                    num.pop_back();
                    int res;
                    if (symbols[symbols.size()-1]=='*')
                    {
                        res=num1*num2;
                    }
                    if (symbols[symbols.size()-1]=='/')
                    {
                        res=num2/num1;
                    }
                    num.push_back(res);
                    symbols.pop_back();
                }
            }
        }
        reverse(num.begin(),num.end());
        reverse(symbols.begin(),symbols.end());
        // cout<<"done"<<endl;
        while(symbols.size()>0)
        {
            int num1=num[num.size()-1];
                    num.pop_back();
                    int num2=num[num.size()-1];
                    num.pop_back();
                    int res;
                    if (symbols[symbols.size()-1]=='+')
                    {
                        res=num1+num2;
                    }
                    if (symbols[symbols.size()-1]=='-')
                    {
                        res=num1-num2;
                    }
                    num.push_back(res);
                    symbols.pop_back();
        }
        return num[0];
    }
};