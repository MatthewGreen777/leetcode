/*
leetcode problem #141: Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached 
again by continuously following the next pointer. Internally, pos is used to denote the 
index of the node that tail's next pointer is connected to. Note that pos is not passed 
as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };


bool hasCycle(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = curr;
    int progress = 0;
    while (curr != nullptr && curr->next != nullptr) {
        prev = prev->next;
        curr = curr->next->next;
        if (prev == curr && curr != nullptr) {
            return true;
        }
    }
    return false;
}