/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }

    int height(TreeNode* node, int& diameter){
        if(node==nullptr)
        return 0;
   // calculates the height of the left subtree and stores it in the variable l, 
   //while also potentially updating the diameter value if needed.
    int l=height(node->left,diameter);
    int r=height(node->right,diameter);
    diameter=max(diameter,l+r);
    return 1 + max(l,r);
    }
};