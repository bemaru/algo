/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <stdio.h>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
class Solution {
    queue<TreeNode*> q;
    TreeNode* cur;

    public:
    void flatten(TreeNode* root) {

        if (root == NULL)
            return;

        dfs(root);
        
        while (true) {
            cur = q.front();
            q.pop();

            if (q.empty()) 
                break;

            cur->right = q.front();
            cur->left = nullptr;
        }

        print_dfs(root);
    }

    void dfs(TreeNode* node) {
        if (node) {
            q.push(node);
            printf("push %d\n", node->val);
            dfs(node->left);
            dfs(node->right);
        }
    }

    void print_dfs(TreeNode* node)
    {
        if (node)
        {
            printf("%d ", node->val);
            print_dfs(node->left);
            print_dfs(node->right);
        }
    }
};


void main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution().flatten(root);
}