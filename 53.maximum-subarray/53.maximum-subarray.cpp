/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int maxans = nums[0];
        for(int i = 0; i < nums.size(); ++i) {
            pre = max(nums[i], pre + nums[i]);
            maxans = max(pre, maxans);
        }
        return maxans;
    }
};
// @lc code=end

