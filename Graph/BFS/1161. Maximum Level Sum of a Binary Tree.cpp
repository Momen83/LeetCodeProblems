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
        queue<TreeNode *>q;
        q.push(root);
        int level = 1;
        int mxLevel = 1;
        int mxVal = q.front()->val;

        while(q.size() > 0) {
            int sum = 0;
            int sz = q.size();
            bool added = false;
            level++;
            while(sz --){
                  TreeNode * curr = q.front();
                  q.pop();

                if(curr->left) {
                    sum+=((curr->left)->val);
                    q.push(curr->left);
                    added = true;
                }
                if(curr->right) {
                    sum+=((curr->right)->val);
                    q.push(curr->right);
                    added = true;
                }
            }
            if(added) {
                if(mxVal < sum) {
                    mxVal = sum;
                    mxLevel = level;
                }
            }
           
        }

        return mxLevel;
    }
};
