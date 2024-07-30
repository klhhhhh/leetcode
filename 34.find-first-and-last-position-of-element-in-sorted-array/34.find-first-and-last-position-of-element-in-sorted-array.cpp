/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binsearch(nums, target);
        if(start == nums.size()|| nums[start] != target){
            return {-1,-1};
        }
        int end = binsearch(nums, target + 1);
        return {start,end - 1};
    }
    int binsearch(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] >= target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

