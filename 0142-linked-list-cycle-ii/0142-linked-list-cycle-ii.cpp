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

 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mpp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(mpp.count(temp)!=0)
            return temp;
            mpp[temp]=1;
            temp=temp->next;
        }
        return nullptr;
    }
};