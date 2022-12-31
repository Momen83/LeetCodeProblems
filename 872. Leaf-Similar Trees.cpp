
class Solution {
public:
   void trav(TreeNode* root , vector<int>&e){
        if(root ==nullptr){
            return ;
        }
        if(root->left ==nullptr  &&root->right ==nullptr){
           e.push_back(root->val);
        }
       
         trav(root->left,e);
         trav(root->right,e);

   }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>e1,e2;
       trav(root1,e1);
       trav(root2,e2);
       return e1 ==e2;
    }
};
