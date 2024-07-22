/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return selectkth(nums, k);
    }

    int selectkth(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        vector<int> min, max, equal;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == pivot) equal.push_back(nums[i]);
            else if(nums[i] > pivot) max.push_back(nums[i]);
            else min.push_back(nums[i]);
        }
        if(k <= max.size()) return selectkth(max, k);
        else if(k > nums.size() - min.size()) return selectkth(min, k - nums.size() + min.size());
        else return pivot;
    }
};
// @lc code=end

