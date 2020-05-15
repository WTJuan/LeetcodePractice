
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr) return head;
        ListNode *ansRoot = new ListNode(0);
        ansRoot->next = head;
        ListNode *preNode = ansRoot;
        ListNode *curNode = head;
        ListNode *nextNode = head->next;
        int loopCount = 0;
        bool isChecking = false;
        while(curNode != nullptr){
            int currentVal = curNode->val;
            if(nextNode == nullptr) {
                if(isChecking){
                    preNode->next = nullptr;
                }
                break;
            }
            int nextVal = nextNode->val;
            if(nextVal == currentVal){
                nextNode = nextNode->next;
                isChecking = true;
            }else{
                if(isChecking){
                    preNode->next = nextNode;
                    curNode = nextNode;
                    nextNode = nextNode->next;
                    if(curNode != nullptr){
                        nextNode = curNode->next;
                    }
                    isChecking = false;
                }else{
                    preNode = curNode;
                    curNode = nextNode;
                    nextNode = nextNode->next;
                }
            }
        }
        return ansRoot->next;
    }
};