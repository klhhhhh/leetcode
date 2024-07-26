/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int i = 0, j = 0;
        vector<int> bound = {n - 1, m - 1, 0, 0};
        vector<int> directions = {0, 1, 0, -1, 0};
        int direction = 0;
        while (res.size() < m * n) {
            
            res.push_back(matrix[i][j]);
            if (direction % 2 ==0 && j == bound[direction] && i == bound[(direction + 3) % 4]) {
                if(direction == 0)
                    bound[(direction + 3) % 4]++;
                if(direction == 2)
                    bound[(direction + 3) % 4] --;
                direction = (direction + 1) % 4;
            }
            else if (direction % 2 ==1 && i == bound[direction] && j == bound[(direction + 3) % 4]) {
                if(direction == 1)
                    bound[(direction + 3) % 4]--;
                if(direction == 3)
                    bound[(direction + 3) % 4]++;
                direction = (direction + 1) % 4;
            }

            i += directions[direction];
            j += directions[(direction + 1) % 4];
        }
        return res;
    }
};
// @lc code=end

