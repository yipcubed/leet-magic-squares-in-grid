#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <utility>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/magic-squares-in-grid/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:


    bool isMagic(vector<vector<int>> &grid, int r, int c) {
        const static vector<pair<int, int>> cords{
                make_pair(0, 0), make_pair(0, 1), make_pair(0, 2),
                make_pair(1, 0), make_pair(1, 1), make_pair(1, 2),
                make_pair(2, 0), make_pair(2, 1), make_pair(2, 2)
        };
        if (grid[r + 1][c + 1] != 5) return false;
        int row = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        if (row != 15) return false;
        int col = grid[r][c] + grid[r + 1][c] + grid[r + 2][c];
        if (col != 15) return false;
        int diag = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        if (diag != 15) return false;
        vector<int> seen(10);
        for (const auto &p : cords) {
            if (grid[r + p.first][c + p.second] < 1 ||
                grid[r + p.first][c + p.second] > 9 ||
                ++seen[grid[r + p.first][c + p.second]] > 1)
                return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid) {
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        int sum = 0;
        for (int r = 0; r < grid.size() - 2; ++r) {
            for (int c = 0; c < grid[r].size() - 2; ++c) {
                if (isMagic(grid, r, c))
                    ++sum;
            }
        }
        return sum;
    }
};

void test1() {
    vector<vector<int>> v1{
            vector<int>{4, 3, 8, 4},
            vector<int>{9, 5, 1, 9},
            vector<int>{2, 7, 6, 2}
    };

    cout << "1 ? " << Solution().numMagicSquaresInside(v1) << endl;

    vector<vector<int>> v2{
            vector<int>{5, 5, 5},
            vector<int>{5, 5, 5},
            vector<int>{5, 5, 5}
    };

    cout << "0 ? " << Solution().numMagicSquaresInside(v2) << endl;

    vector<vector<int>> v3{
            vector<int>{1, 8, 6},
            vector<int>{10, 5, 0},
            vector<int>{4, 2, 9}
    };

    cout << "0 ? " << Solution().numMagicSquaresInside(v3) << endl;
}

void test2() {

}

void test3() {

}