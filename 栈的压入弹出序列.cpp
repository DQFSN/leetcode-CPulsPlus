//
// Created by 段其沣 on 2020-09-19.
//

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
    bool check(vector<int> ph, vector<int> pp) {

        stack<int> in;

        int pp_index = 0;
        for (auto x : ph) {
            in.push(x);

            while (!in.empty() && in.top() == pp[pp_index]) {
                cout<<in.top()<<endl;
                in.pop();
                pp_index++;
            }
        }

        return in.empty() && pp_index == pp.size();
    }

};


int main() {
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {5, 4, 2, 3, 1};

    cout<<Solution().check(push, pop)<<endl;


    return 0;
}
