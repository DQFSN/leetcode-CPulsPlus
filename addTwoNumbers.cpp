//
// Created by 段其沣 on 2020-09-18.
//

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;

//    explicit ListNode(int x) : val(x), next(nullptr){};
//    ListNode(int x, ListNode* next) : val(x), next(next){};
};

using namespace std;

class Solution {
public:
    ListNode* addTwoList(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* ans = new ListNode{1, nullptr};
        ListNode* tear = ans;
        int carry = 0;
        while (l1 || l2) {
            int a = l1 == nullptr ? 0 : l1->val;
            int b = l2 == nullptr ? 0 : l2->val;
            int c = (a + b + carry) % 10;
            if ((a + b + carry) / 10){
                carry = 1;
            }

            ListNode* temp = new ListNode{c};
            tear->next = temp;
            tear = tear->next;

            l1 = l1 == nullptr ? nullptr: l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;

        }

        if (carry) {
            return ans;
        }else {
            return ans->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode{1};
        ListNode* tail = ans;
        int carry = 0;

        while (l1 || l2) {
            int a = l1 == nullptr ? 0 : l1->val;
            int b = l2 == nullptr ? 0 : l2->val;
            int c = (a + b + carry) % 10;
            carry = (a + b + carry) > 10 ? 1 : 0;

            ListNode* temp = new ListNode{c};
            tail->next = temp;
            tail = tail->next;

            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }

        return carry ? ans : ans->next;
    }

//private:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = new ListNode{0};


        ListNode* next = nullptr;
        while (head){
//            cout<<head->val<<"->";
            next = head->next;
            head->next = ans->next;
            ans->next = head;
            head = next;
        }

        return ans->next;
    }

};


int main() {

    ListNode list[4]  ;
    list[0] = ListNode{0, &list[1]};
    list[1] = ListNode{1, &list[2]};
    list[2] = ListNode{2, &list[3]};
    list[3] = ListNode{3, nullptr};

    ListNode list2[4]  ;
    list2[0] = ListNode{0, &list2[1]};
    list2[1] = ListNode{1, &list2[2]};
    list2[2] = ListNode{2, &list2[3]};
    list2[3] = ListNode{3, nullptr};

//    ListNode* head = Solution().addTwoList(list, list2);
    ListNode* head = Solution().addTwoNumbers(Solution().reverseList(list), Solution().reverseList(list2) );


    while (head){
        if (head->next) {
            cout<<head->val<<"->";
        }else {
            cout<<head->val<<endl;
        };
        head = head->next;
    }

    return 0;
}