//
// Created by 段其沣 on 2020-09-21.
//

#include <iostream>

using namespace std;

class Solution {

public:

    long NumberOf1Between1AndN_Solution(int n)
    {
        long count = 0;

        long i = 1;

        long current = 0,after = 0,before = 0;

        while((n / i) != 0)
        {
            before = n / (i * 10);
            current = (n / i) % 10;
            after = n - (n / i) * i;


            if (current >= 1)
            {
                // 如果current大于1，则出现1的次数为其高位before的数字加1
                count += (before + 1) * i;
            }
            else if (current == 0)
            {
                //  如果current位数为0, 1出现位数出现是其高位数字before
                count += before * i;
            }

            else if(current == 1)
            {
                //  如果current等于1，则1出现的次数为其高位before + 其低位after
                count += (before + after) + 1;
            }

            i = i * 10;

        }

        return count;

    }

    long numOf1(int n) {
        long count = 0;
        long i = 1;

        long current = 0, after = 0, before = 0;

        while (n / i) {
            before = n / (i * 10);
            current = n % 10;
            after = n - (n / i) * i;

            if (current > 1) {
                count += (before + 1) * i;
            }else if (current == 0) {
                count += before * i;
            }else if (current == 1) {
                count += (before + after) + 1;
            }

            i *= 10;
        }

        return count;
    }
};


int main() {

    cout<<Solution().numOf1(99999)<<endl;
    cout<<Solution().NumberOf1Between1AndN_Solution(99999)<<endl;
    return 0;
}
