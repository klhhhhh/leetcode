/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end(), MyComparator());
        int len = intervals.size();
        vector<int> current_interval = intervals[0];
        for(int i = 1; i < len; i++){
            if(current_interval[1] >= intervals[i][0]){
                current_interval[1] = max(intervals[i][1], current_interval[1]);
            }
            else{
                results.push_back(current_interval);
                current_interval = intervals[i];
            }
        }
        results.push_back(current_interval);
        return results;
    }
    struct MyComparator {
        bool operator()(vector<int> a, vector<int> b) const {
            // 自定义排序逻辑，例如按照绝对值大小排序
            return a[0] < b[0];
        }
    };
};
// @lc code=end

