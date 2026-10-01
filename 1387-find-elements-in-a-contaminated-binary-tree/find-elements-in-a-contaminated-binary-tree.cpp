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
class FindElements {
public:
    int leftval(int n){return (2*n)+1;}
    int rightval(int n){return (2*n)+2;}
    unordered_set<int> st;

    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        root->val = 0;
        q.push({root});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                st.insert(node->val);
                if(node->left){
                    q.push(node->left);
                    node->left->val = leftval(node->val);
                }
                if(node->right){
                    q.push(node->right);
                    node->right->val = rightval(node->val);
                }
            }
        }
    }
    
    bool find(int target) {
        if(st.count(target)>0){return 1;}
        else{return 0;}
    }
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */