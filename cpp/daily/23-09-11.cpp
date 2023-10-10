#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

auto solution(std::vector<int> groupSizes) -> std::vector<std::vector<int>> {
    
    std::unordered_map<int, std::vector<int>> groups{};

    for (int i = 0; i < groupSizes.size(); ++i) {
        if (groups.find(groupSizes[i]) == groups.end()) {
            groups[groupSizes[i]] = {i};
        } else {
            groups[groupSizes[i]].push_back(i);
        }
    }

    std::vector<std::vector<int>> result;

    for (auto const& group : groups) {
        if (group.second.size() == group.first) {
            result.push_back(group.second);
        } 
        else {
            for (int j = 0; j < group.second.size() / group.first; ++j) {
                std::vector<int> g;
                g.resize(group.first);

                for (int k = 0; k < group.first; ++k) {
                    g[k] = group.second[j * group.first + k];
                }
                result.push_back(g);
            }
        }
    }
    return result;
}


TEST(Test23_09_11, Case1) {
    std::vector<std::vector<int>> expected = {{5}, {0,1,2}, {3,4,6},};
    ASSERT_EQ(solution({3, 3, 3, 3, 3, 1, 3}), expected);
}
