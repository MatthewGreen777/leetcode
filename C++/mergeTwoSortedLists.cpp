/*
leetcode problem #21: Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made 
by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *curr1 = list1;
    ListNode *curr2 = list2;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int val = 0;

    while (curr1 != nullptr || curr2 != nullptr) {
        if (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val > curr2->val) {
                val = curr2->val;
                curr2 = curr2->next;
            } else {        
                val = curr1->val;
                curr1 = curr1->next;
            }
        } else if (curr1 != nullptr && curr2 == nullptr) {       
            val = curr1->val;  
            curr1 = curr1->next;
        } else {        
            val = curr2->val;
            curr2 = curr2->next;
        }
    if (head == nullptr) {
        head = new ListNode(val);
        tail = head;
    } else {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    }

    return head;        
}