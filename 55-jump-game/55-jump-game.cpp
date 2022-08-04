class Solution {
public:
    bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n,0);
		dp[n-1] = 1;
		for(int ind=n-2;ind>=0;ind--){
			bool temp = false;
			for(int i=1;i<=nums[ind];i++){
				if(ind+i < n) temp = temp || dp[ind+i];
				if(temp==1) break;
			}
			dp[ind] = temp;
		}
		return dp[0];
	}
};