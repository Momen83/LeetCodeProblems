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
    int mx = 0;
    void solve(TreeNode* root , int h ,int dir){
      if(root ==nullptr)return;
       mx = max(mx , h);
       solve(root->left , h +(dir&1 ?1:-(h-1)),0);
       solve(root->right , h +(dir <=0 ?1:-(h-1)),1);
          
    }
    int longestZigZag(TreeNode* root) {
        solve(root,0,-1);
        return mx;
    }
};
