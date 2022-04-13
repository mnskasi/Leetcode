class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int i=0;
        int j=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> res;
        int dir=0;
        for (int ind=1;ind<=m*n;ind++)
        {
            res.push_back(matrix[i][j]);
            matrix[i][j]=1000;
            if (dir==0 )
            {
                if (j+1 < n and matrix[i][j+1] < 1000)
                {
                    j++;
                }
                else
                {
                    dir=1;
                    i++;
                }
            }
            else if (dir==1)
            {
                if (i+1 < m and matrix[i+1][j] < 1000)
                {
                    i++;
                }
                else
                {
                    dir=2;
                    j--;
                }
            }
            else if (dir==2)
            {
                if (j-1 >=0 and matrix[i][j-1] < 1000)
                {
                    j--;
                }
                else
                {
                    dir=3;
                    i--;
                }
            }
            else if (dir==3)
            {
                if (i-1 >=0 and matrix[i-1][j] < 1000)
                {
                    i--;
                }
                else
                {
                    dir=0;
                    j++;
                }
            }
        }
        return res;
    }
};