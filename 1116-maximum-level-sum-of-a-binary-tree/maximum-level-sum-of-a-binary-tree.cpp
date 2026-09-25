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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){return 0;}

        int level=1;
        int ans=1;

        queue<TreeNode*> q;
        int maxi=root->val;
        vector<vector<int>> res;
        q.push(root);

        while(!q.empty()){
            vector<int> lvl;
            int size = q.size();
            int currmax=0;
            bool accept = false;
            level++;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    accept = true;
                    q.push(node->left);
                    lvl.push_back(node->left->val);
                    currmax+=(node->left->val);
                }
                if(node->right){
                    accept = true;
                    q.push(node->right);
                    lvl.push_back(node->right->val);
                    currmax+=(node->right->val);
                }
            }
            if(currmax>maxi && accept){
                maxi = currmax;
                ans = level;
            }
        }
        return ans;
    }
};