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
    ListNode* reverseList(ListNode* head) {

        ListNode* ans = new ListNode{0};
        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            head->next = ans->next;
            ans->next = head;
            head = next;
        }

        return ans->next;
    }

    ListNode* reverseList01(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;

        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};


int main() {

    ListNode list[4];

    list[0] = ListNode{0, &list[1]};
    list[1] = ListNode{1, &list[2]};
    list[2] = ListNode{2, &list[3]};
    list[3] = ListNode{3, nullptr};

//    ListNode* head = Solution().reverseList(list);
    ListNode* head = Solution().reverseList01(list);

    while (head) {
        cout<<head->val<<" ";

        head = head->next;
    }


    return 0;
}