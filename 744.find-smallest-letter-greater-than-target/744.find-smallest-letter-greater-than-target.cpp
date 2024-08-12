/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        if(letters[right] <= target) return letters[0];
        while(left <= right){
            int mid = (left + right)/2;
            if((char)(target + 1) > letters[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return letters[left];
    }
};
// @lc code=end

