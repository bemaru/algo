#include <stdio.h>
#include "common.h"
#include <iostream>

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class BSTIterator {
    queue<int> q;
    public:
    BSTIterator(TreeNode *root) {
        dfs(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    /** @return the next smallest number */
    int next() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    void dfs(TreeNode* node) 
    {
        if (!node)
            return;

        dfs(node->left);
        q.push(node->val);
        dfs(node->right);
    }
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

void main()
{
    //string str = "[18,7,26,3,12,21,31]";
    string str = "[1]";
    TreeNode* root = stringToTreeNode(str);
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();

    return;
}