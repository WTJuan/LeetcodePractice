struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *node1 = head;
        ListNode *node2 = head->next;
        ListNode *node3 = node2->next;
        ListNode *ans = node2;
        node2->next = node1;
        node1->next = node3;
        head = node3;
        ListNode *preNode = node1;
        while(head!=nullptr){
            node1 = head;
            node2 = head->next;
            if(node2!=nullptr){
                ListNode *node3 = node2->next;
                preNode->next = node2;
                node2->next = node1;
                node1->next = node3;
                head = node3;
                preNode = node1;
            }else{
                head = head->next;
            }
        }
        return ans;  
    }
};