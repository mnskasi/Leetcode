class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        int temp=poured;
        // cout<<"temp is "<<temp<<endl;
        if (query_row==0 and query_glass==0)
        {
            if (poured==0)
            {
                return 0.0;
            }
            else
            {
                return 1;
            }
        }
        vector< vector<double> > arr;
        for (int x=0;x<=query_row;x++)
        {
            vector<double> mark;
            for (int y=0;y<=x;y++)
            {
                if (x==query_row and y==query_glass)
                {
                    if (y==0 )
                    {
                        double val= arr[x-1][y]/2.0;
                        if (val > 1)
                        {
                            return 1.0;
                        }
                        else
                        {
                            return val;
                        }
                    }
                    else if (y==query_row)
                    {
                        double val= arr[x-1][y-1]/2.0;
                        if (val > 1)
                        {
                            return 1.0;
                        }
                        else
                        {
                            return val;
                        }
                    }
                    else
                    {
                        double val= (arr[x-1][y-1]+arr[x-1][y])/2.0;
                        if (val > 1)
                        {
                            return 1.0;
                        }
                        else
                        {
                            return val;
                        }
                    }
                }
                else
                {
                    if (x==0 and y==0)
                    {
                        if (temp > 1)
                        {
                            mark.push_back(temp-1.0);
                        }
                        else
                        {
                            mark.push_back(0);
                        }
                        
                    }
                    else if (y==0 )
                    {
                        double val=arr[x-1][y]/2.0;
                        if (val > 1)
                        {
                            mark.push_back((arr[x-1][y]/2.0)-1.0);
                        }
                        else
                        {
                            mark.push_back(0);
                        }
                    }
                    else if (y==x)
                    {
                        // mark.push_back(arr[x-1][y-1]/2.0);
                        double val=arr[x-1][y-1]/2.0;
                        if (val > 1)
                        {
                            mark.push_back((arr[x-1][y-1]/2.0)-1.0);
                        }
                        else
                        {
                            mark.push_back(0);
                        }
                    }
                    else
                    {
                        // mark.push_back((arr[x-1][y-1]+arr[x-1][y])/2.0);
                        double val=(arr[x-1][y-1]+arr[x-1][y])/2.0;
                        if (val > 1)
                        {
                            mark.push_back((val)-1.0);
                        }
                        else
                        {
                            mark.push_back(0);
                        }
                    }
                }
                // cout<<"x is "<<x<<" y is "<<y<<" "<<" val is "<<arr[x][y]<<endl;
            }
            arr.push_back(mark);
        }
        return 0.0;
    }
};