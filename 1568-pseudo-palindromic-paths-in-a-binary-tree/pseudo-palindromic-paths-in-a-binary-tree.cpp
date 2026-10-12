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
    void dfs(TreeNode* root,unordered_map<int,int> &mpp,int &cnt){
        
        if(root==NULL){return;}
        mpp[root->val]++;
        // if(mpp.find(root->val)!=mpp.end()){
        //     mpp[root->val]++;
        // }
        // else{mpp[root->val]=0;}

        if(!(root->left) && !(root->right)){
            int oddnum=0;
            int evennum=0;
            for(auto it:mpp){
                if(it.second%2==0){evennum++;}
                else{oddnum++;}
            }
            if(oddnum<2){
                cnt++;
            }
        }
        dfs(root->left,mpp,cnt);
        dfs(root->right,mpp,cnt);
        mpp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mpp;
        int cnt=0;
        dfs(root,mpp,cnt);
        return cnt;
    }
};