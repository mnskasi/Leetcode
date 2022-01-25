class Solution {
public:
    string getPermutation(int n, int k) 
    {
        int fact=1;
        vector<int>num;
        for (int i=1;i<=n;i++)
        {
            num.push_back(i);
            fact*=i;
        }
        fact/=n;
        string ans="";
        k=k-1;
        for (int i=0;i<n;i++)
        {
            ans+=to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            k=k%fact;
            if (num.size()==0) break;
            fact/=num.size();
        }
        return ans;
    }
};