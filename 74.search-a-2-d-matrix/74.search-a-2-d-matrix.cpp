/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            int mid_val = matrix[mid / n][mid % n];
            if(target < mid_val){
                right = mid - 1;
            }
            else if(target > mid_val){
                left = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

