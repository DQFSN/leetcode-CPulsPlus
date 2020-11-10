//
// Created by 段其沣 on 2020-09-19.
//


#include <map>

using namespace std;

struct RandomListNode {
    int val;
    RandomListNode* next;
    RandomListNode* rand;
};

class Solution {

public:
    RandomListNode* clone(RandomListNode* head) {

        if (head == nullptr) return nullptr;

        map<RandomListNode*, RandomListNode*> m;

        RandomListNode* nList = new RandomListNode{0};
        RandomListNode* nHead = nList;
        RandomListNode* srcHead = head;


        RandomListNode* next = nullptr;

        while (head) {
            next = head->next;
            RandomListNode* temp = new RandomListNode{head->val};
            m[head] = temp;
            nList->next = temp;
            nList = nList->next;
            head = next;
        }

        head = nHead->next;
        while (head) {
            next = head->next;

            head->rand = m[srcHead];

            head = next;
            srcHead = srcHead->next;
        }

        return nHead;
    }
};