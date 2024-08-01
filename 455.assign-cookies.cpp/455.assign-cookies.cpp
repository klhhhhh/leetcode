/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int len_s = s.size();
        int cookie = 0;
        int child;
        for(child = 0; child < g.size();){
            if(cookie == len_s)
                break;
            if(g[child] <= s[cookie]){
                child++;
            }
            cookie++;
        }
        return child;
    }
};
// @lc code=end

