/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int maxlen = 1;
        // vector<int> dp(nums.size(), 1);
        // for(int i = 0; i < nums.size(); ++i) {
        //     for(int j = 0; j < i; ++j) {
        //         if(nums[i] > nums[j]) {
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        //     maxlen = max(dp[i], maxlen);
        // }
        // return maxlen;

        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                int left = 0;
                int right = dp.size()-1;
                while(left < right) {
                    int mid = (right+left)/2;
                    if(nums[i] <= dp[mid]) {
                        right = mid;
                    } else if(nums[i] > dp[mid]) {
                        left = mid + 1; 
                    }
                }
                dp[left] = nums[i];
            }
        }
        return dp.size();
    }
};
// @lc code=end

