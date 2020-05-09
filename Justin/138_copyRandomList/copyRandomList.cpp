#include <vector>
#include <map>

using namespace std;
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

Node* copyRandomList(Node* head) {
    if(head == nullptr) return nullptr;
    map<Node*,Node*> myMap;
    Node *copiedHead = new Node(head->val);
    myMap[head] = copiedHead;
    Node *fHead = head;
    Node *sHead = copiedHead;
    head = head->next;
    while(head!=nullptr)
    {
        Node *copiedNode = new Node(head->val);
        myMap[head] = copiedNode;
        copiedHead->next = copiedNode;
        head = head->next;
        copiedHead = copiedNode;
    }
    Node *ssHead = sHead;
    while(fHead != nullptr){
        if(fHead->random != nullptr){
            ssHead->random = myMap[fHead->random];
        }
        fHead = fHead->next;
        ssHead = ssHead->next;
    }
    return sHead;
}

int main(int argc, char *argv[])
{
    Node *root = new Node(7);
    Node *node1 = new Node(13);
    Node *node2 = new Node(11);
    Node *node3 = new Node(10);
    Node *node4 = new Node(1);
    root->next = node1;
    node1->next = node2;
    node1->random = root;
    node2->next = node3;
    node2->random = node4;
    node3->next = node4;
    node3->random = node2;
    node4->random = root;

    Node *ansNode = copyRandomList(root);
    while (ansNode != nullptr)  
    {
        printf("%d\n",ansNode->val);
        ansNode = ansNode->next;
    }

    return 0;
}
