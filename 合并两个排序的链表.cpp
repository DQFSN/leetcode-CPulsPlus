//
// Created by 段其沣 on 2020-09-19.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode{0};
        ListNode* res = ans;

        ListNode* next = nullptr;

        while (l1 && l2) {
            if (l1->val >= l2->val) {
                next = l1->next;
                ans->next = l1;
                ans = ans->next;
                l1 = next;
            }else {
                next = l2->next;
                ans->next = l2;
                ans = ans->next;
                l2 = next;
            }
        }

        if (l1) {
            ans->next = l1;
        } else {
            ans->next = l2;
        }


        return res->next;
    }
};


int main() {

    ListNode list1[4];
    list1[0] = ListNode{3, &list1[1]};
    list1[1] = ListNode{2, &list1[2]};
    list1[2] = ListNode{1, &list1[3]};
    list1[3] = ListNode{0, nullptr};


    ListNode list2[5];
    list2[0] = ListNode{3, &list2[1]};
    list2[1] = ListNode{2, &list2[2]};
    list2[2] = ListNode{1, nullptr};

    ListNode* result = Solution().mergeList(list1, list2);

    while (result) {
        cout<<result->val;
        result = result->next;
    }

    return 0;
}