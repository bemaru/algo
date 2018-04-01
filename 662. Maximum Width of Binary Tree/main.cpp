//https://leetcode.com/problems/maximum-width-of-binary-tree/description/

/*
Given a binary tree, write a function to get the maximum width of the given tree. 
The width of a tree is the maximum width among all levels. 
The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes 
(the leftmost and right most non-null nodes in the level, 
where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).


Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).


Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).


Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
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
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

    map<int,vector<int>> levelMap;
    int treeDepth = 0;
    int maxWidth = 0;

    public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        dfs(root, 0, 1);

        vector<int> sameLevelNodes;
        int levelWidth;

        for (int i = 0; i < levelMap.size();i++) 
        {
            sameLevelNodes = levelMap[i];

            levelWidth = sameLevelNodes.back() - sameLevelNodes.front() + 1;
            maxWidth = max(maxWidth, levelWidth);
        }

        return maxWidth;
    }

    void dfs(TreeNode* node, int level, int seq) 
    {
        if (node == nullptr) 
            return;

        treeDepth = max(treeDepth, level);
        
        levelMap[level].emplace_back(seq);
        
        dfs(node->left, level + 1, seq * 2 - 1);
        dfs(node->right, level + 1, seq * 2);
    }
};

class Solution2 {
    int maxWidth = 0;
    public:
    int widthOfBinaryTree(TreeNode* root) {
        bfs(root);
        return 0;
    }
    int level = 0;
    void bfs(TreeNode* node) {
        queue<TreeNode*> q;

        printf("%d : ", level);
        q.push(node);
        q.push(nullptr);
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            if (node == nullptr) {
                
                q.push(nullptr);
                if (q.front() == nullptr) {
                    break;
                }

                level++;
                printf("\n%d : ", level);
            }
            else {
                printf("%d ", node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);

    /*TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);*/

   
    printf("sol : %d\n", Solution().widthOfBinaryTree(root));

    return 0;
}
