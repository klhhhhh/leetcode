/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int pre1 = 1;
        int pred2 = 2;
        if(n==1)return 1;
        if(n==2)return 2;
        int cur;
        for(int i = 3; i <= n; i++){
            cur = pre1 + pred2;
            pre1 = pred2;
            pred2 = cur;
        }
        return cur;
    }
};
// @lc code=end

