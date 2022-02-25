class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<int> col (matrix[0].size(),0);
        for (int i=0;i<matrix.size();i++)
        {
            for (int j=0;j<matrix[0].size();j++)
            {
                if (matrix[i][j]==0)
                {
                    for (int k=0;k<matrix[0].size();k++)
                    {
                        if (matrix[i][k]==0)
                        {
                            col[k]=1;
                        }
                        matrix[i][k]=0;
                    }
                    break;
                }
            }
        }
        for (int j=0;j<matrix[0].size();j++)
        {
            if (col[j]==1)
            {
                for (int i=0;i<matrix.size();i++)
                {
                    matrix[i][j]=0;
                }
            }
            
        }
    }
};