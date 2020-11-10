//
// Created by 段其沣 on 2020-09-18.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution{
public:
    vector<vector<string> > groupAnagrams(vector<string> &str) {
        vector<vector<string>> result;
        map<string, int> m;

        for (int i = 0; i < str.size(); i++) {
            string word = str[i];
            sort(word.begin(), word.end());
            if (m.find(word) != m.end()) {
                vector<string> v;
                v.push_back(str[i]);
                result.push_back(v);
                m[word] = result.size() - 1;
            } else {
                result[m[word]].push_back(str[i]);
            }
        }

        for (int i = 0; i < result.size(); i++){
            sort(result[i].begin(), result[i].end());
        }

        return result;
    }

    vector<vector<string>> groupAnagrams01(vector<string> &strs) {
        vector<vector<string>> result;
        map<string, multiset<string>> m;

        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            m[word].insert(strs[i]);
        }

        for (auto item : m) {
            vector<string> v(item.second.begin(), item.second.end());
            result.push_back(v);
        }

        return result;
    }

};

