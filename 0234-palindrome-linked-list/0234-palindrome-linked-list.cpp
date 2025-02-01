/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*
 BRUTE FORCE-
 declare temp at head
 declare a stack
 in the stack traverse the elements using temp
 push the elements in the stack
 now again declare temp at head
 compare the value at temp node to the value at the top of the stack
 pop the elements
 if at any point the values do not match stop coz the string is not a palindrome

 OPTIMAL APPROACH-
 take slow and fast pointer 
 move slow by 1
 fast by 2
 reverse the linked list where the slow pointer is
 point to the second reversed half
 return reverse linked list(newHead)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* secondHalf = reverseList(slow->next);
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        // Compare both halves
        while (temp != NULL) {
            if (firstHalf->val != temp->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // Restore the original list (optional)
        slow->next = reverseList(secondHalf);

        return true;
    }
};
