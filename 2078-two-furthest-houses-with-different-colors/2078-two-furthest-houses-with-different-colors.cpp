class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int max1=INT_MIN;
        for (int i=0;i<colors.size();i++)
        {
            for (int j=0;j<colors.size();j++)
            {
                if (colors[i]!=colors[j] and max1 < abs(i-j))
                {
                    max1=abs(i-j);
                }
            }
        }
        return max1;
    }
};