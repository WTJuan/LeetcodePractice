
//這題簡單，只需要紀錄進位數字，並在每次加總時加入
//然後更新進位數字，沿著 list trace 一遍即可。
//時間複雜度: O(n+m), n 為 list 1 長度, m 為 list 2 長度
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ext = 0;
        ListNode *ansRoot = new ListNode(0);
        ListNode *tempRoot = ansRoot;
        while(l1 != nullptr || l2 != nullptr)
        {
            int val1 = 0;
            int val2 = 0;
            if(l1 != nullptr){
                val1 = l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            int temp = (ext+val1+val2)%10;
            ext = (ext+val1+val2)/10;
            ListNode *node = new ListNode(temp);
            tempRoot->next = node;
            tempRoot = node;
        }
        if(ext!=0){
            ListNode *node = new ListNode(ext);
            tempRoot->next = node;
        }
        return ansRoot->next;
    }
};