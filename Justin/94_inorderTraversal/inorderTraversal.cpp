#include <vector>
#include <stack>

using namespace  std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *preNode = nullptr;
    while (1)
    {
        if(root != nullptr){
            st.push(root);
            root = root->left;
            continue;
        }

        if(root == nullptr && st.empty()){
            return ans;
        }
        preNode = st.top();
        st.pop();
        ans.push_back(preNode->val);

        if(preNode->right != nullptr){
            root = preNode->right;
            continue;
        }
        if(st.empty()) break;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    TreeNode root = TreeNode(1);
    TreeNode node1 = TreeNode(2);
    TreeNode node2 = TreeNode(3);
    root.right = &node1;
    node1.left = &node2;

    vector<int> ans = inorderTraversal(&root);
    for(int i=0;i<ans.size();i++){
        printf("%d ",ans[i]);
    }
    printf("\n");

    return 0;
}