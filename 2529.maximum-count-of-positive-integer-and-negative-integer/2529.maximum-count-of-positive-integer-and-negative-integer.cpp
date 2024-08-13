/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
class Solution {
public:
    int maximumCount(vector<int>& nums) {
    
        int left = binary_search(nums, 0);
        if(left >= nums.size() || nums[left] != 0)
            return left > nums.size() - left ? left : nums.size() - left;
        int right = binary_search(nums, 1) - 1;
        return left > nums.size() - right - 1? left : nums.size() - right - 1;
    }
    int binary_search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

