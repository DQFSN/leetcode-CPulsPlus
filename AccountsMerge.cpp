//
// Created by 段其沣 on 2020-09-18.
//

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;



class Solution_Time_Limit_Exceeded{
public:
    vector<vector<string>> accountMerge(vector<vector<string> >& accounts){
        unordered_map<string, string> email_chains;
        unordered_map<string, string> names;


        for (int i = 0; i < accounts.size(); i++){
            auto& account = account[i];
            auto& name = account[0];

            for (int j = 1; j < account.size(); j++){
                auto& email = account[0];
                if (names.find(email) == names.end()){
                    email_chains[email] = email;
                    names[email] = name;
                }
            }

            join(email_chains, account[1], email);
        }


        unordered_map<string, set<string>> res;

        for (auto& acc : accounts){
            string e = find(email_chains);
            res[e].insert(acc.begin()+1, acc.end());
        }

        vector<vector<string>> result;
        for (auto pair : res){
            vector<string> emails(pair.second.begin(), pair.second.end());
            emails.insert(emails.begin(), names[pair.first]);
            result.push_back(emails);
        }



    }


};