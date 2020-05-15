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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead -> next = head;
        ListNode* curr = dummyHead;
        
        int repeatNum = 0;
        while(curr != NULL){
            if(
                curr -> next != NULL &&
                curr -> next -> next != NULL &&
                curr -> next -> val == curr -> next -> next -> val
            ){
                repeatNum = curr -> next -> val;
                while(curr -> next != NULL && curr -> next -> val == repeatNum){
                    curr -> next = curr -> next -> next;
                }
            }else {
                curr = curr -> next;   
            }
        }
        
        return dummyHead -> next;
    }
};