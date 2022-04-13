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
        vector< vector<int> > arr(m, vector<int> (n,0));
        for (int ind=1;ind<=m*n;ind++)
        {
            arr[i][j]=1;
            res.push_back(matrix[i][j]);
            if (dir==0 )
            {
                if (j+1 < n and arr[i][j+1]==0)
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
                if (i+1 < m and arr[i+1][j]==0)
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
                if (j-1 >=0 and arr[i][j-1]==0)
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
                if (i-1 >=0 and arr[i-1][j]==0)
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