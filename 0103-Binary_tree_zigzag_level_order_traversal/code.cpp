// #include <iostream>

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* current = dummyHead;
//         int carry = 0;

//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
//             carry = sum / 10;

//             current->next = new ListNode(sum % 10);
//             current = current->next;

//             if (l1) l1 = l1->next;
//             if (l2) l2 = l2->next;
//         }

//         return dummyHead->next;
//     }
// };

// // Function to print a linked list
// void printList(ListNode* head) {
//     while (head) {
//         std::cout << head->val << " ";
//         head = head->next;
//     }
//     std::cout << std::endl;
// }

// int main() {
//     // Example usage
//     Solution solution;

//     // Create two linked lists representing numbers
//     ListNode* l1 = new ListNode(2);
//     l1->next = new ListNode(4);
//     l1->next->next = new ListNode(3);

//     ListNode* l2 = new ListNode(5);
//     l2->next = new ListNode(6);
//     l2->next->next = new ListNode(4);

//     // Call the function to add two numbers represented by linked lists
//     ListNode* result = solution.addTwoNumbers(l1, l2);

//     // Print the result
//     std::cout << "Result: ";
//     printList(result);

//     // Cleanup
//     delete l1;
//     delete l2;

//     // Clean up the result list (assuming it's dynamically allocated)
//     while (result) {
//         ListNode* temp = result;
//         result = result->next;
//         delete temp;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
