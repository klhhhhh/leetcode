/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if((len1 + len2)%2 == 0){
            return (findk(nums1, nums2, 0, len1 - 1, 0, len2 - 1, (len1 + len2) / 2) + findk(nums1, nums2, 0, len1 - 1, 0, len2 - 1, (len1 + len2) / 2 + 1)) / 2.0;
        }
        else{
            return findk(nums1, nums2, 0, len1 - 1, 0, len2 - 1, (len1 + len2) / 2 + 1);
        }
    }
    int findk(vector<int> &nums1, vector<int> &nums2, int start1, int end1, int start2, int end2, int k){

        if(start1 > end1){
            return nums2[start2 + k - 1];
        }
        if(start2 > end2){
            return nums1[start1 + k - 1];
        }
        if(k == 1){
            return min(nums1[start1], nums2[start2]);
        }

        int len1 = min(end1 - start1 + 1, k / 2);
        int len2 = min(end2 - start2 + 1, k / 2);

        int value1 = nums1[start1 + len1 - 1];
        int value2 = nums2[start2 + len2 - 1];
        if(value1 < value2){
            return findk(nums1, nums2, start1 + len1, end1, start2, end2, k - len1);
        }
        else{
            return findk(nums1, nums2, start1, end1, start2 + len2, end2, k - len2);
        }
    }
};
// @lc code=end

