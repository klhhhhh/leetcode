/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if(k == 0) return;
        reverse(nums, 0, len - k - 1);
        reverse(nums, len - k, len - 1);
        reverse(nums, 0, len - 1);
    }
    void reverse(vector<int>& nums, int start, int end){
        for(int i = start; i < start + (end - start)/2 + 1; i++){
            int temp = nums[i];
            nums[i] = nums[end - (i - start)];
            nums[end - (i - start)] = temp; 
        }
    }
};
// @lc code=end

