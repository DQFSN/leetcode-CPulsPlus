//
// Created by 段其沣 on 2020-09-19.
//


#include <iostream>
#include <vector>

using namespace std;


class Solution {
    int n, m;
    vector<vector<bool> > v;
    bool judge(int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m && !v[i][j];
    }
public:

    void printMatrix(vector<vector<int>> array) {
        n = array.size();
        m = array[0].size();

        if (n == 0 || m == 0) return;

        int count = n * m;
        v = vector<vector<bool>>(n, vector<bool>(m, false));
        int opt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0, j = 0;
        int d = 0;

        while (count) {
            cout<<array[i][j]<<" ";
            v[i][j] = true;
            if (!judge(i + opt[d][0], j + opt[d][1])) {
                d = d + 1;
                d = d % 4;
            }

            i = i + opt[d][0];
            j = j + opt[d][1];
            count--;
        }
    }
};


int main() {
    vector<vector<int>> martix{{1, 2, 3}, {3, 2, 1}};

    Solution().printMatrix(martix);

    return 0;
}


