/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

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
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    stack<TreeNode*> temp;

    TreeNode* _p;
    TreeNode* _q;

    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        _p = p;
        _q = q;
        dfs(root);
        
        if (s1.size() > s2.size()) {
            temp = s1;
            s1 = s2;
            s2 = temp;
        }

        while (s1.size() != s2.size())
            s2.pop();

        while (s1.top() != s2.top()) {
            s1.pop();
            s2.pop();
        }

        return s1.top();
    }

    void dfs(TreeNode* node) {
        if (node) {
            temp.push(node);

            if (node == _p)
                s1 = temp;

            if (node == _q)
                s2 = temp;

            dfs(node->left);
            dfs(node->right);

            temp.pop();
        }
    }
};

void main()
{

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    printf("%d\n", Solution().lowestCommonAncestor(root, root->left->right->left, root->left->left)->val);
}