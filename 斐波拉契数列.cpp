//
// Created by 段其沣 on 2020-09-18.
//


#include <vector>

using namespace std;

class Solution{
public:
    int n fibonacci(int n) {
        if (n < 3)  return 1;
        int front = 1, back = 1;

        for (int i = 3; i <= n; i++) {
            int c = front + back;
            front = back;
            back = c;
        }

        return back;
    }
};
