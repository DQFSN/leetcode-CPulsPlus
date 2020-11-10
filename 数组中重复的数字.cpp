//
// Created by 段其沣 on 2020-09-18.
//
#include <vector>
#include <iostream>


using namespace std;


class Solution{
public:
    int findRepate(vector<int>& array) {

        for (int i = 0; i < array.size(); i++) {
            if (array[i] != array[array[i]] || i == array[i] ) {
                array[array[i]] = array[i];
            } else {
                return array[i];
            }
        }

        return INT_MAX;
    }

    bool duplicate(vector<int>& array) {

        for (int i = 0; i < array.size(); i++) {
            if (i != array[i]){
                int m = array[i];
                if (m == array[m]) {
                    cout<<"重复数字："<<m<<endl;
                }else {
                    array[m] = m;
                }
            }
        }
    }
};

int main() {
    vector<int> array = {0,0};

    cout<<"重复数字是："<<Solution().duplicate(array)<<endl;


    return 0;
}