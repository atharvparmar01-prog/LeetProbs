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
    void preorder(TreeNode* root,int &n,int maxi){
        if(root==NULL){return;}
        int par = root->val;
        if(root->val >= maxi){
            cout<<root->val<<endl;
            maxi = root->val;
            n++;
        }

        preorder(root->left,n,maxi);
        preorder(root->right,n,maxi);
        maxi = par;
    }
    int goodNodes(TreeNode* root) {
        int n=0;
        preorder(root,n,root->val);
        return n;
    }
};