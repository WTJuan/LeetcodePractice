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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* ans = NULL;
        ListNode* curr = NULL;
        while(l1 != NULL || l2 != NULL || carry == true){
            int sum = 0;
            if(carry == true){
                sum += 1;
                carry = false;
            }
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2 -> next;
            }
            if(sum >= 10){
                sum -= 10;
                carry = true;
            }
            
            ListNode* newEle = new ListNode(sum);
            if(ans == NULL){
                ans = newEle;
                curr = ans;
            }else {
                curr -> next = newEle;
                curr = curr -> next;
            }
        }
        
        return ans;
    }
};