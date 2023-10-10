#include <vector>

#include <gtest/gtest.h>

using std::vector;

vector<int> searchRange(vector<int>& nums, int target) {

    if (nums.size() == 0) return {-1,-1};

    // binary search
    //
    size_t start = 0;
    size_t end = nums.size();

    size_t middle = (end + start) / 2;

    do {
        if (nums[middle] > target) {
            end = middle;
        }
        else if (nums[middle] < target) {
            start = middle;
        }
        else break;
        middle = (end + start) / 2;
    } while(end - start > 1);

    if (nums[middle] != target) return {-1,-1};

    size_t b = middle;
    size_t e = middle;
    for(; b > 0 && nums[b-1] == target; --b) { }
    for(; e < nums.size()-1 && nums[e+1] == target; ++e) { }

    return {
        static_cast<int>(b),
        static_cast<int>(e)
    };
}

void test(std::vector<int> nums, int target, std::vector<int> result) {
    ASSERT_EQ(searchRange(nums, target), result);
}

TEST(Test23_10_09, Case1) {
    test({5,7,7,8,8,10}, 8, {3,4});
}

TEST(Test23_10_09, Case2) {
    test({5,7,7,8,8,10}, 6, {-1,-1});
}

TEST(Test23_10_09, Case3) {
    test({}, 0, {-1,-1});
}

TEST(Test23_10_09, Case4) {
    test({1}, 1, {0,0});
}

TEST(Test23_10_09, Case5) {
    test({1,2,3}, 3, {2,2});
}
