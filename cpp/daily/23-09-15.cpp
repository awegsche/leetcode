#include <iostream>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

struct point {
    int x;
    int y;

    int distance(point const & p) const {
        return std::abs(x - p.x) + std::abs(y - p.y);
    }
};

struct connection {
    point a;
    point b;

    int distance() const {
        return a.distance(b);
    }
};

struct vertex {
    int cost;
    point prev;
    point next;
};

int cost(std::vector<point> const & points) {

    return 0;
}

int minCost(std::vector<std::vector<int>> const & points) {

    std::vector<point> points_;
    points_.reserve(points.size());
    for (auto const & p: points) {
        points_.push_back({p[0], p[1]});
    }

    return cost(points_);
}
TEST(daily23_09_15, Case1) {
    //ASSERT_EQ(minCost({{0,0}, {2,2}, {3,10}, {5,2}, {7,0}}), 20);  
}
