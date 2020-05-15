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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead -> next = head;
        ListNode* curr = dummyHead;
        while(curr != NULL){
            if(curr -> next == NULL || curr -> next -> next == NULL){
                break;
            }
            
            ListNode* temp = curr -> next -> next -> next;
            curr -> next -> next -> next = curr -> next;
            curr -> next = curr -> next -> next;
            curr -> next -> next -> next = temp;
            
            curr = curr -> next -> next;
        }
        
        return dummyHead -> next;
    }
};