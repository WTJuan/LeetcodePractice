#include <stack>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    int totalCount = 0;
        ListNode *headBuff = head;
        vector<ListNode *> list;
        while(headBuff!=nullptr){
            list.push_back(headBuff);
            totalCount+=1;
            headBuff = headBuff->next;
        }
        
        int targetN = totalCount - n - 1;
        if(targetN < 0){
            if(totalCount>1){
                return list[1];
            }else{
                return nullptr;
            }
        }else{
            if(targetN + 1 < list.size()){
                ListNode* preNode = list[targetN];
                ListNode* nextNode = list[targetN+1];
                preNode->next = nextNode->next;
                delete nextNode;
            }
        }
        return head;
}

int main(int argc, char *argv[]){
    
    ListNode *root = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    root->next = node1;

    ListNode *ansRoot = removeNthFromEnd(root,2);

    while (ansRoot!=nullptr)
    {
        printf("%d -> ",ansRoot->val);
        ansRoot = ansRoot->next;
    }
    
    return 0;
}
