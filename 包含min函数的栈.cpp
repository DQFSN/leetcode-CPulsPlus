//
// Created by 段其沣 on 2020-09-19.
//


#include <stack>

using namespace std;

class Solution {
    stack<int> data;
    stack<int> min;

public:

    void push(int n) {

        data.push(n);

        if (min.size() == 0 || n < min.top()) {
            min.push(n);
        }else {
            min.push(min.top());
        }
    }

    int pop() {
        if (!data.empty()) {
            min.pop();
            return data.pop();
        }

        return 0;
    }


    int min() {
        return min.top();
    }
};


int main() {


    return 0;
}
