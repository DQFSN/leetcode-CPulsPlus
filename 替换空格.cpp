//
// Created by 段其沣 on 2020-09-18.
//

#include <iostream>
#include <string>


using namespace std;


class Solution{
public:
    string replaceSpace(string a) {

        int count = 0;
        for (auto x : a) {
            if (x == ' ')
                count++;
        }
        string b(a.size() + count * 2,' ');
        int alen = a.size();
        int blen = b.size();

        while (alen) {
            if (a[alen - 1] == ' '){
                b[blen - 1] = '0';
                blen--;
                b[blen - 1] = '2';
                blen--;
                b[blen - 1] = '%';
                blen--;
                alen--;
            } else {
                b[blen - 1] = a[alen - 1];
                blen--;alen--;
            }
        }

        return b;
    }
};


int main() {
    string a = "ab  cs ";

    cout<<"result: "<<Solution().replaceSpace(a)<<endl;


    return 0;
}
