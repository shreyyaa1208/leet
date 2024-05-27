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
create temp pointer which will start from null
traverse the temp pointer untill it reaches null
while traversing store the elements in the hashmap
when a element is present twice return true else false
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mpp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()){
                return true;
            }
            mpp[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};