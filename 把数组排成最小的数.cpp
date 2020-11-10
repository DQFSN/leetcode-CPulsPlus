//
// Created by 段其沣 on 2020-09-21.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

template <class T>
string ToString(const T& t) {
    ostringstream oss;

    oss<<t;
    return oss.str();
}

class Solution {

public:
    static bool compare(const string& left, const string& right) {
        string leftright = left + right;
        string rightleft = right + left;

        return leftright < rightleft;
    }

    string printMinNum(vector<int> array) {
        string res = "";
        string str;

        vector<string> strNum;

        for (auto x : array) {
            str = ToString(x);
            strNum.push_back(str);
        }

        sort(strNum.begin(), strNum.end(),compare);

        for (auto s : strNum) {
            res += s;
        }

        return res;

    }

};


int main() {

    vector<int> array = {12,34,2,3,33,55};

    cout<<Solution().printMinNum(array)<<endl;
    return 0;
}

