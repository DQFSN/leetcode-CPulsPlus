//
// Created by 段其沣 on 2020-09-18.
//

//#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    bool isAnagram(string s1, string s2) {
        int map[26] = {0};

        for (auto c : s1) {
            map[c - 'a']++;
        }

        for (auto c : s2) {
            map[c - 'a']--;
        }

        for (auto i : map) {
            if (i != 0) return false;
        }

        return true;
    }
};

int main() {
    string a = "abcs";
    string b = "csca";

    cout<<Solution().isAnagram(a, b)<<endl;
}

