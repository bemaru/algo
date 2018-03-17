/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.


Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

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
#include <limits.h>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
class Solution {
      
    bool flag = true;
    public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }

    int dfs(TreeNode* node) {
        int leftDepth = 0;
        int rightDepth = 0;

        if (node == NULL)
            return 0;

        if (node->left == NULL && node->right == NULL)
            return 1;

        if (node) {
            leftDepth = dfs(node->left);
            rightDepth = dfs(node->right);

            if (abs(leftDepth - rightDepth) > 1)
                flag = false;
                       
            return max(leftDepth, rightDepth)+1;
        }
    }
};

void main()
{
    /*TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);*/

    /*TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);*/

    /*TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);*/

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    if (Solution().isBalanced(root)) 
    {
        printf("true\n");
    }
    else 
    {
        printf("false\n");
    }
}

