//
// Created by 段其沣 on 2020-09-18.
//


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};


class Solution{
public:
    ListNode* findkthNode(ListNode* head, int k) {

        ListNdoe* slow = head;

        while(head && k){
            head = head->next;
            k--;
        }

        if (head == nullptr) return nullptr;

        while (head) {
            head = head->next;
            slow = slow->next;
        }

        retrun slow;
    }
};


int main() {

    ListNode list[4];
    list[0] = ListNode{0, &list[1]};
    list[1] = ListNode{1, &list[2]};
    list[2] = ListNode{2, &list[3]};
    list[3] = ListNode{3, nullptr};

    cout<<Solution().findKthNode(list, 2)->val<<endl;

    return 0;
}
