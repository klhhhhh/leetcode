/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix.back().back();
        while (right > left) {
            int mid = left + (right - left) / 2;
            if (check(matrix, k, n, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    bool check(vector<vector<int>>& matrix, int k, int n, int mid) {
        int count = 0;
        for (int i = n - 1 , j = 0; i >= 0 && j < n;) {
            if (matrix[i][j] <= mid) {
                count += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return count <= k;
    }
};
// @lc code=end

