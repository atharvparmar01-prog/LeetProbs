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
    void dfs(TreeNode* root,string flag,int &maxi,int cnt){
        if(root==NULL){return;}
        if(cnt>maxi){
            maxi=cnt;
        }
        if(flag=="right"){
            dfs(root->left,"left",maxi,cnt+1);
            dfs(root->right,"right",maxi,1);
        }
        else if(flag=="left"){
            dfs(root->left,"left",maxi,1);
            dfs(root->right,"right",maxi,cnt+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        string l = "left";
        string r = "right";
        int maxi = 0;
        int cnt=1;
        dfs(root->left,l,maxi,cnt);
        dfs(root->right,r,maxi,cnt);
        return maxi;
    }
};