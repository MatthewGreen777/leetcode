// problem #2095

/*
You are given the head of a linked list. Delete the 
middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the 
⌊n / 2⌋^th node from the start using 0-based 
indexing, where ⌊x⌋ denotes the largest integer 
less than or equal to x.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head);
};


int main() {
    Solution nodes;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    node4->next = node5;

    ListNode* track = node1;
    while (track != nullptr) {
        std::cout << track->val << std::endl;
        track = track->next;
    }
    track = node1;
    std::cout << std::endl;
    nodes.deleteMiddle(node1);
    while (track != nullptr) {
        std::cout << track->val << std::endl;
        track = track->next;
    }
    return 0;
}

ListNode* Solution::deleteMiddle(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    int total = 0;
    ListNode *track = head;
    while (track != nullptr) {
        total++;
        track = track->next;
    }
    track = head;
    for (int i = 0; i < ((total/2) - 1); i++) {
        track = track->next;
    }
    if (track == head && track->next == nullptr) {
        delete track;
        track = nullptr;
        return nullptr;
    } else {
        ListNode* track2 = track->next;
        if (track2 != nullptr) {
            if (track2->next == nullptr) {
                track->next = nullptr;
            } else {
                track->next = track2->next;
            }
            delete track2;
            track2 = nullptr;
        } 
    }
    return head;;
}