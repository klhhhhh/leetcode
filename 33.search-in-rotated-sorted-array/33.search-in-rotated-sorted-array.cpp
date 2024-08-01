/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(is_after(nums, target, mid)){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
    
    bool is_after(vector<int>& nums, int target, int mid){
        int end = nums.back();
        if(target > end){
            if(nums[mid] > end){
                if(nums[mid] < target)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else{
            if(nums[mid] > end){
                return true;
            }
            else{
                if(nums[mid] < target)
                    return true;
                else
                    return false;
            }
        }
    }
};
// @lc code=end

