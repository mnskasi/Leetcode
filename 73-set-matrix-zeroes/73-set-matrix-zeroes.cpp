class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
       int m = matrix.size();
        int n = matrix[0].size();
        if(m==1 && n==1)
        {
            return;
        }
        
        bool row_flag = false;
        bool col_flag = false;
        
        //check for any zero in 1st row                
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                row_flag = true;
            }
           
        }
        
        //check for any zero in 1st col               
         for(int i=0;i<m;i++)
        {
             if(matrix[i][0]==0)
            {
                col_flag = true;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                //set only 1st row and 1st col to zero
                if(matrix[i][j]==0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
		//using inspace auxillary space as first row and first column, make submatrix values to be zero
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j] =0;
                }
            }
        }
        
        if(row_flag)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i] = 0;
            }
        }
        
        if(col_flag)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        

    }
};