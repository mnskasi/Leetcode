class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector< vector<int> > arr(n, vector<int> (n,0));
        int i=0;
        int j=0;
        int dir=0;
        for (int ind=1;ind<=n*n;ind++)
        {
            arr[i][j]=ind;
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
                if (i+1 < n and arr[i+1][j]==0)
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
        return arr;
    }
};