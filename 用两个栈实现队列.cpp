//
// Created by 段其沣 on 2020-09-18.
//

#include <stack>
#include <iostream>

using namespace std;

class Solution{
public:
    void pop() {
        if (!out.empty()) {
            out.pop();
        }else {

            if (!in.empty()) {
                while (!in.empty()) {
                    out.push(in.top());
                    in.pop();
                }

                out.pop();
            }else {
                cout<<"空"<<endl;
            }
        }
    }

    void push(int a) {
        in.push(a);
    }

    int front() {
        retrun out.top();
    }

private:
    stack<int> in;
    stack<int> out;
};
