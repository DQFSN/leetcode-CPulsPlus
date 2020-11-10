//
// Created by 段其沣 on 2020-09-21.
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int getUglyNum(int index) {
        if (index <= 0) return 0;

        if (index == 1) return 1;

        set<long> st;
        set<long>::iterator it;
        set.insert(2);
        set.insert(3);
        set.insert(5);

        for (it = st.begin(); it != st.end(); it++) {
            int len = st.size();

            if (len >= index * 2) break;

            st.insert(*it * 2);
            st.insert(*it * 3);
            st.insert(*it * 5);
        }

        int count = 0;
        for (auto x : st) {
            count++;
            if (count == index - 1) {
                return num;
            }
        }

        return 0;
    }
};

int main() {

    cout<<Solution().getUglyNum(3)<<endl;
    return 0;
}