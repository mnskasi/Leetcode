class Solution {
public:
    int noofways (int n,int arr[])
    {
        if (n==1 or n==2)
        {
            return n;
        }
        if (arr[n]!=-1)
        {
            return arr[n];
        }
        arr[n]=noofways(n-1,arr)+noofways(n-2,arr);
        return arr[n];
        
    }
    int climbStairs(int n) 
    {
        int arr[n+1];
        for (int i=0;i<=n;i++)
        {
            arr[i]=-1;
        }
        return noofways(n,arr);
    }
};