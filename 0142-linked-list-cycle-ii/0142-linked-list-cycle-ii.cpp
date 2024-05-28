/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 BRUTE FORCE-
 create a hashmap
 create a temp at head
 traverse temp till it reaches null
 check if (mp.count(temp)!=0) means the check if temp has been encountered again
 a loop is detected hence return temp
 store the value of temp=1
 do temp=temp->next 

 OPTIMIZED APPROACH-
 take two pointers fast and slow
 start them from head
 traverse till fast and fast.next !=null
 if fast==slow
 return slow=head
 now to find the first node in the loop
 traverse slow.next and fast.next
 return slow
 return null

 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                 slow=head;
                 while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                 }
                 return slow;
            }
        
        }
        return NULL;
    }
};