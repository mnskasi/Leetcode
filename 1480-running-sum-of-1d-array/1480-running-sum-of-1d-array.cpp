class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> res;
        for (auto i: nums) {
            sum += i;
            res.push_back(sum);
        }
        return res;
    }
};