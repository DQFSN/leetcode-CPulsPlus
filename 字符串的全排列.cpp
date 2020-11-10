//
// Created by 段其沣 on 2020-09-20.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
protected:
    vector<string> m_res;
public:

    vector<string> permutation(string str) {
        m_res.clear();

        if (str.empty()) {
            return m_res;
        }

        sort(m_res.begin(), m_res.end());
        permutationRecursion(str, 0);

        return m_res;
    }

private:

    void permutationRecursion(string str, int begin) {

        if (str[begin] == '\0') {
            m_res.push_back(str);
        }else {

            for (int i = begin; str[i] != '\0'; i++) {

                if (!isDuplicate(str, begin, i)) {
                    swap(str[begin], str[i]);
                    permutationRecursion(str, begin + 1);
                    swap(str[begin], str[i]);
                }

            }

        }

    }

    bool isDuplicate(string& str, int k, int l) {

        for (int i = k; i < l; i++) {
            if (str[i] == str[l]) return true;
        }

        return false;

    }
};


int main() {
    string a = "abc";
    vector<string> res = Solution().permutation(a);

    for (auto x : res) {
        cout<<x<<" ";
    }

    return 0;
}
