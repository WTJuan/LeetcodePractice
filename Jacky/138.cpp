// 解題想法：
// 先 loop 一次 linked list 建立新的 Node，並存到 Map 中
// 第二次 loop 綁定對應的 Node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> newNodeList;
        Node *curr = head;
        
        Node *newHead = NULL;
        Node *newCurr = NULL;
        while(true){
            if(curr == NULL){
                break;
            }
            
            Node *nextNode = new Node(curr->val);
            newNodeList.insert(pair<Node*, Node*>(curr, nextNode));
            
            if(newHead == NULL){
                newHead = nextNode;
                newCurr = nextNode;
            }else{
                newCurr -> next = nextNode;
                newCurr = nextNode;
            }
            
            curr = curr -> next;
        }
        
        newCurr = newHead;
        curr = head;
        
        while(true){
            if(curr == NULL){
                break;
            }
            
            if(curr->random != NULL){
                auto iter = newNodeList.find(curr->random);
                if(iter != newNodeList.end()){
                    newCurr -> random = iter -> second;
                }else{
                    newCurr -> random = NULL;
                }
            }else{
                newCurr -> random = NULL;
            }
            
            newCurr = newCurr -> next;
            curr = curr -> next;
        }
        
        return newHead;
    }
};