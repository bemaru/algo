/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

#include <stdio.h>

//Definition for singly-linked list.

#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        
        if (head->val == -100)
            return head;

        head->val = -100;
        return detectCycle(head->next);
    }
};

void main()
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);

    a->next = b;
    b->next = c;
    //c->next = a;

    //a = a->next;
    //a->next = a;
    
    printf("%d\n",Solution().detectCycle(a)->val);

    ListNode* cur;
    cur = a;
    while (cur) 
    {
        printf("%d\n", cur->val);
        cur = cur->next;
    }

    

}