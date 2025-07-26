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
class Solution {
public:
ListNode* solve(ListNode* l1, ListNode* l2, int carry){
    if(l1==nullptr && l2==nullptr && carry==0){
        return nullptr;
    }
    int val1=(l1!=nullptr)?l1->val:0;
    int val2=(l2!=nullptr)?l2->val:0;
    int sum=val1+val2+carry;

    ListNode* newNode=new ListNode(sum%10);
     ListNode* next_l1 = (l1 != nullptr) ? l1->next : nullptr;
        ListNode* next_l2 = (l2 != nullptr) ? l2->next : nullptr;
        newNode->next = solve(next_l1, next_l2, sum / 10);

        return newNode;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        return solve(l1, l2, 0);
    }
};