//
// Created by 段其沣 on 2020-09-18.
//

#include <iostream>
#include <stack>

struct ListNode{
    int val;
    ListNode* next;
};

using namespace std;

class Solution{
public:
    void printListFromTailToHeadByrevsesing(ListNode* head) {
        ListNode* ans = new ListNode{0};

        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            head->next = ans->next;
            ans->next = head;
            head = next;
        }

        next = ans->next;
        while (next){
            cout<<next->val<<" ";
            next = next->next;
        }
    }


    void printListFromTailToHeadBystack(ListNode* head) {
        stack<int> stk;
        while (head) {
            stk.push(head->val);
            head = head->next;
        }

        while (!stk.empty()) {
            cout<<stk.top()<<" ";
            stk.pop();
        }

    }
};


int main() {
    ListNode list[4];
    list[0] = ListNode{1,&list[1]};
    list[1] = ListNode{2,&list[2]};
    list[2] = ListNode{3,&list[3]};
    list[3] = ListNode{4, nullptr};

    Solution().printListFromTailToHeadBystack(list);
    Solution().printListFromTailToHeadByrevsesing(list);

    return 0;
}

