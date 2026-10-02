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
    bool transform(TreeNode* root, int target){
        if(root==NULL){return true;}
        bool l = transform(root->left,target);
        bool r = transform(root->right,target);

        if(l){root->left = NULL;}
        if(r){root->right = NULL;}

        if((root->val == target) && l && r){return true;}
        else{return false;}

    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(transform(root,target)){return NULL;}
        else{return root;}
    }
};