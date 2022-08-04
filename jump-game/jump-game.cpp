class Solution {
public:
    bool solve(int ind, vector<int> &nums,vector<bool> & canReach, vector<int> &visited) {
        for (int i= 1;i<= nums[ind];i++) {
            if (i+ind >= nums.size()) {
                return false;
            }
            if (i + ind == nums.size() - 1) {
                return true;
            }
            if (visited[ind+i] != 1) {
                canReach[ind+i] = solve(ind + i, nums, canReach, visited);
                visited[ind + i] = 1;
            }
            
            if (canReach[ind+i]) {
                return true;
            }
            
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        vector<int> visited(nums.size(),0);
        vector<bool> canReach(nums.size(), false);
        return solve(0,nums,canReach,visited);
    }
};