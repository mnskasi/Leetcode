class Solution {
public:
    int binarysearch(vector<int>& nums,int target, int l, int r)
    {
        if (l<=r)
        {
            int mid=l+(r-l)/2;
            if (nums[mid]==target)
            {
                return mid;
            }
            else if (nums[mid]<target)
            {
                return binarysearch(nums,target,mid+1,r);
            }
            else
            {
                return binarysearch(nums,target,l,mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        return binarysearch(nums,target,0,nums.size()-1);
    }
};