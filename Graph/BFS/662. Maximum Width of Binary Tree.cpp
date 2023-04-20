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
// 15 -1 
    int widthOfBinaryTree(TreeNode* root) {
        // Represent the tree and the position of each node
        queue<pair<TreeNode *,long long>>q;
        // Push the start node and the start position
        q.push({root, 0});
        // Represent the max width
        int maxWidth = 0;

        while(!q.empty()) {
            // the size of current level
            int sz = q.size();

            // the previous postion
            int prevPos = q.front().second;
            //Represent the left most position and right most position
            int leftMost = 0 , rightMost = 0;

            //Iterate over the current level

            for(int level = 0 ; level <sz ; level++) {

                // Represent current node
                TreeNode * curr = q.front().first;

                // represent current poition
                long long pos = q.front().second - prevPos ;
                q.pop();
                
                if(curr->left !=nullptr) {
                    q.push({curr->left , 2 * pos + 1});
                
                }
            
                if(curr->right !=nullptr){ 
                    q.push({curr->right , 2 * pos + 2});
                 
                }
                

                if(level == 0) {
                    leftMost = pos;
                }
                if(level ==sz - 1){
                    rightMost = pos;
                }
              

            }
         

              maxWidth = max(maxWidth , rightMost - leftMost + 1);
          
         
        }
    
    return maxWidth;
    }
};
