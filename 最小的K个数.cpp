#include <iostream>
#include <vector>

//当基准数选择最左边的数字时，那么就应该先从右边开始搜索；当基准数选择最右边的数字时，那么就应该先从左边开始搜索。不论是从小到大排序还是从大到小排序！
using namespace std;


class Solution {

public:
    void sort(vector<int>& array, int begin, int end) {

        if (begin >= end) return ;

        if (end - begin == 1) {
            if (array[begin] > array[end]){
                array[end] = array[end] + array[begin] - array[end];
                array[begin] = array[end] + array[begin] - array[begin];
            }
            return ;
        }

        int pivotIndex = begin, pivotNum = array[pivotIndex];
        int left = begin, right = end;

        while (left < right) {

            while (left < right && array[right] >= array[pivotIndex]) right--;
            while (left < right && array[left] <= array[pivotIndex]) left++;

            swap(array[left], array[right]);
        }


        if (array[left] >= array[pivotIndex]) {
            ;
        }else {
            swap(array[left], array[pivotIndex]);
        }

        sort(array, begin, pivotIndex - 1);
        sort(array, pivotIndex + 1, end);

    }
};

int main() {

    vector<int> array = {4,2,3,5,2,7};
    Solution().sort(array, 0 , array.size() - 1);

    for (auto x : array) {
        cout<<x<<" ";
    }

    return 0;
}