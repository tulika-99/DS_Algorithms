#include <bits/stdc++.h>

// Definition for singly-linked list.
typedef struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
}ListNode;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                l1 -> next = mergeTwoLists (l1 -> next, l2);
                return l1;
            }
            else {
                l2 -> next = mergeTwoLists (l1, l2 -> next);
                return l2;
            }
        }
        else if (l1) return l1;
        else if (l2) return l2;
        else return NULL;
    }
};