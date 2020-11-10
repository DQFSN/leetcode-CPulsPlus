//
// Created by 段其沣 on 2020-09-18.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    void swapeven(vector<int>& array) {
        int front = 0, back = array.size() - 1;

        for (int i = front, j = back; i < j;  ) {
            while (array[i] % 2 == 1) i++;
            while (array[j] % 2 == 0) j--;

            if (i < j) {
                swap(array[i], array[j]);
            }

            i++;j--;
        }
    }
};


int main() {

    vector<int> array{0,1,2,3,4,5,6};

    Solution().swapeven(array);

    for (auto x : array) {
        cout<<x<<" ";
    }
    return 0;
}
