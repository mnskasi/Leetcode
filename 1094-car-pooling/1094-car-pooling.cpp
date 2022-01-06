class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int>flag(1001,0);
        for (auto i:trips)
        {
            for (int j=i[1];j<i[2];j++)
            {
                flag[j]+=i[0];
            }
        }
        if (*max_element(flag.begin(),flag.end()) <= capacity)
        {
            return true;
        }
        return false;
    }
};