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
 divide into two sub-problems
 1. count the total length
 2.do(L-N+1)
 first w will count the total nodes till it reaches null
 once we have got the total count. Store it.
 now initialize temp pointer to the start 
 initialize a variable res=L-N
 start iterating the linked list while decrementing res at each node. 
 Once res equals 0, we know that temp will be pointing to the (L-N)th node, 
 therefore, stop the traversal.
 create a new link from (L-N)th node to (L-N+2)node

 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        return NULL;
        int count=0;
ListNode* temp=head;
while(temp!=NULL){
count++;
temp=temp->next;
}
if(count==n){
    ListNode* newHead=head->next;
    delete(head);
    return newHead;
}
int res=count-n;
temp=head;
while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

ListNode* delNode=temp->next;
temp->next=temp->next->next;
delete(delNode);
return head;
        
    }
};