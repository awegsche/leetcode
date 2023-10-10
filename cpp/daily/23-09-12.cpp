#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>


int find_deletions(std::string const& s) {
    std::unordered_map<char, int> freqs;

    for (char c: s) {
        auto found = freqs.find(c);

        if (found != freqs.end()) {
            ++found->second;
        }
        else {
            freqs[c] = 1;
        }
    }

    auto maxfreq = std::max_element(freqs.cbegin(), freqs.cend(),
            [](auto a, auto b){ return a.second < b.second; })->second;

    std::vector<int> count{};
    count.resize(maxfreq+2);
    //std::cout << "maxfreq: " << maxfreq << "; ";

    for (auto const &[k, v]: freqs) {
        ++count[v];
        //std::cout << k << ": " << v << ", ";
    }
    //std::cout << std::endl;


    int ndels = 0;
    bool deletions = true;

    while (deletions) {
        deletions = false;

        size_t last_0 = 0;

        for (int i = 1; i <= maxfreq+1; ++i) {
            if (count[i] == 0) last_0 = i;
            else if (count[i] > 1) {
                --count[i];
                count[last_0] = 1;
                ndels += (i - last_0);
                deletions = true;
                break;
            }
        }

        //for (int i: count) {
            //std::cout << i << " |";
        //}
        //std::cout << std::endl;
    }

    return ndels;
}

void run_testcase(std::string const& s) {
    std::cout << "Testcase \"" << s << "\"" << std::endl;

    std::cout << "ndels: " << find_deletions(s) << std::endl;
}

TEST(Daily23_09_12, testcase) {
    
    run_testcase("abb");
    run_testcase("aaabbbcc");
    run_testcase("ceabaacb");
    run_testcase("bbcebab");
    run_testcase("odofingjfdncnecmfdekekchbbicbflkoanohamkcjljbfmahhbnkiangdal");
}
