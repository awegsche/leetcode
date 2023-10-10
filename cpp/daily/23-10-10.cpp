#include <iterator>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using std::vector;
using std::cout, std::endl;


template<typename It>
int operations(It begin, It end, int dir) {
    for (auto p = begin; p != end; p+=dir) {
        std::cout << *p << ", ";
    }
    std::cout << std::endl;

    auto it = begin;
    auto _end = end;
    int last = *it;
    int count = 0;
    it+=dir;


    for (;it != _end;) {
        if (*it == last) {
            // replace this one instead of the last
            ++count;
            it+=dir;
        }
        else if (*it - last != dir) {
            // replace the last element
            ++count;
            _end-=dir;
        }
        else {
            it+=dir;
        }
        last += dir;
    }

    std::cout << "count = " << count <<std::endl;

    return count;
}

int operations_from_median(vector<int>& nums) {
    const int half_length = nums.size() / 2;
    const int left = operations(nums.begin()+half_length, nums.begin()-1, -1);
    const int right = operations(nums.begin()+half_length, nums.end(), 1);

    cout << "left = " << left
        << ", right = " << right << endl;

    return left+right;
}
int minOperations(vector<int>& nums) {

    std::sort(nums.begin(), nums.end());

    /*
    int last = nums.front();
    int count = 0;
    auto end = nums.end();

    for (auto it = nums.begin()+1; it != end;) {
        if (*it - last > 1) {
            ++count;
            --end; // pick element from the end
        }
        else {
            ++it;
        }
        ++last;
    }
    return count;
    */

    /*
    return std::min(
            operations(nums.begin(), nums.end(), 1),
            operations(nums.end()-1, nums.begin()-1, -1)
            );
            */
    return operations_from_median(nums);
}

void test(vector<int> nums, int expected) {
    ASSERT_EQ(minOperations(nums), expected);
}

TEST(Test23_10_10, Case1) {
    test({4,2,5,3}, 0);
}
TEST(Test23_10_10, Case2) {
    test({1,2,3,5,6}, 1);
}
TEST(Test23_10_10, Case3) {
    test({1,10,100,1000}, 3);
}
TEST(Test23_10_10, Case4) {
    test({41,33,29,33,35,26,47,24,18,28}, 5);
}
