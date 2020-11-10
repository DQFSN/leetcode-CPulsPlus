//
// Created by 段其沣 on 2020-09-16.
//

#include <iostream>
#include <string>

using namespace std;


class Solution{
public:
    string replaceSpace(string str){
        if(str.size()==0){
            return str;
        }

        int len = str.size();
        int count = 0;
        for(int i=0;i<len;i++){
            if(str[i] == ' '){
                ++count;
            }
        }

        int newLen = len + count*2 ;

        string newStr ;
        for(int i=0;i<newLen;i++){
            newStr += ' ';
        }

        while(newLen != 0){
            if(str[len-1] == ' '){
                len--;
                newStr[newLen-1] = '0';
                newLen--;
                newStr[newLen-1] = '2';
                newLen--;
                newStr[newLen-1] = '%';
                newLen--;
            }else{
                newStr[newLen-1] = str[len-1];
                len--;
                newLen--;
            }
        }

        return newStr;

    }
};

int main(){

    string str = "  ddd ";
    Solution solu;
    cout<<solu.replaceSpace(str)<<endl;

    return 0;
};