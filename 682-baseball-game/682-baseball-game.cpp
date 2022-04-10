class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        vector<int> ans;
        for (auto i: ops)
        {
            if (i=="D")
            {
                int num = ans[ans.size()-1];
                ans.push_back(num*2);
            }
            else if (i == "C")
            {
                ans.pop_back();
            }
            else if (i == "+")
            {
                int num1 = ans[ans.size()-1];
                int num2 = ans[ans.size()-2];
                ans.push_back(num1 + num2);
            }
            else
            {
                int num= stoi(i);
                ans.push_back(num);
            }
        }
        int sum=0;
        for (auto i: ans)
        {
            sum += i;
        }
        return sum;
    }
};