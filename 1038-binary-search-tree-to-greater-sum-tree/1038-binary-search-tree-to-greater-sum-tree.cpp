/**Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}};*/
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> inordertrav;
        inorder(root, inordertrav);
        
        reverse(inordertrav.begin(), inordertrav.end());
         
        replaceval(root, inordertrav);
        return root;
    }
  void inorder(TreeNode* root, vector<int>& inordertrav){
      if(root == nullptr){
          return;
      }
      inorder(root-> left, inordertrav);
      inordertrav.push_back(root->val);
      inorder(root->right, inordertrav);
  }  
    void replaceval(TreeNode* root, vector<int>& inordertrav){
        if(root== nullptr){
            return ;
        }
        replaceval(root->left, inordertrav);
        replaceval(root->right, inordertrav);
        
        int nodesum=0;
        for(auto i : inordertrav){
            if(i>root->val){
                nodesum= nodesum+i;
            }
            else{
                break;
            }
        }
        root->val = root->val+nodesum;
    }
};