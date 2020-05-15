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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* first = dummyHead;
        ListNode* second = dummyHead;
        
        int len = 0;
        while(k > 0){
            first = first -> next;
            k--;
            len++;
            
            if(first == NULL && len > 1){
                k = k % (len-1);
                first = head;
            }
        }
        
        while(first != NULL && first -> next != NULL){
            first = first -> next;
            second = second -> next;
        }
        
        ListNode* lastNode = second;
        if(second != dummyHead && second -> next != NULL){
            dummyHead -> next = second -> next;
            second = second -> next;
            lastNode -> next = NULL;
            while(second != NULL){
                if(second -> next == NULL){
                    second -> next = head;
                    break;
                }else{
                    second = second -> next;
                }
            }
        }
        
        return dummyHead -> next;
    }
};