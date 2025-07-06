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
    vector<int> rightSideView(TreeNode* root) {
vector<int>ans;
f(0,root,ans);
return ans;        
    }
    void f(int currLevel,TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        if(currLevel>=ans.size()) ans.push_back(root->val);
        f(currLevel+1,root->right,ans);
        f(currLevel+1,root->left,ans);
           return;
    }
};