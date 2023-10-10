#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using std::vector;

double median(vector<int>& nums) {
    return nums.size() % 2 ? nums[nums.size() / 2] : (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums; 

    nums.insert(nums.end(), nums1.begin(), nums1.end());
    nums.insert(nums.end(), nums2.begin(), nums2.end());

    std::sort(nums.begin(), nums.end());

    return median(nums);
}

void check(vector<int> nums1, vector<int> nums2, double expected) {
    ASSERT_EQ(findMedianSortedArrays(nums1, nums2), expected);
}

TEST(daily23_09_21, case1) {
    check({1,3}, {2}, 2);
}

TEST(daily23_09_21, case2) {
    check({1,3}, {2,4,5}, 3);
}
