// Problem #2: Add Two Numbers

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int overflow = 0;
        ListNode* newList = new ListNode(); 
        ListNode* current = newList;

        ListNode* node1 = l1;       
        ListNode* node2 = l2;

        while (node1 != nullptr || node2 != nullptr) {
            if (node1 != nullptr && node2 != nullptr) {
                sum = node1->val + node2->val + overflow;
                if (sum >= 10) {
                    sum = sum - 10;
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                
                node1 = node1->next;
                node2 = node2->next;
                current->val = sum;
                if (node1 != nullptr || node2 != nullptr) {
                    current->next = new ListNode();
                    current = current->next;
                }
            } else if (node1 != nullptr && node2 == nullptr) {
                sum = node1->val + overflow;                
                if (sum >= 10) {
                    sum = sum - 10;
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                node1 = node1->next;
                current->val = sum;
                if (node1 != nullptr) {
                    current->next = new ListNode();
                    current = current->next;
                }
            } else if (node1 == nullptr && node2 != nullptr) {
                sum = node2->val + overflow;
                if (sum >= 10) {
                    sum = sum - 10;
                    overflow = 1;
                } else {
                    overflow = 0;
                }
                node2 = node2->next;
                current->val = sum;
                if (node2 != nullptr) {
                    current->next = new ListNode();
                    current = current->next;
                }
            }
        }

        if (overflow == 1){
            current->next = new ListNode(overflow);
            current = current->next;
        }

        return newList;
    }
};

int main() {
    // Creating first linked list: 2 -> 4 -> 3 -> 7 -> 1 (represents 17342)
    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(7);
    list1->next->next->next->next = new ListNode(1);

    // Creating second linked list: 5 -> 6 -> 4 -> 8 -> 9 (represents 98465)
    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);
    list2->next->next->next = new ListNode(8);
    list2->next->next->next->next = new ListNode(9);

    // Optional: call addTwoNumbers to test it
    Solution solution;
    ListNode* result = solution.addTwoNumbers(list1, list2);

    // Print the resulting list (currently only prints first node value)
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
