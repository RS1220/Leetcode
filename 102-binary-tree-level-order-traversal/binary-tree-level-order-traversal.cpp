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
    //M2 . vector and preorder
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left) , levels(root->right));
    }
    void print(TreeNode* root , vector<vector<int>>& ans , int level){
          
          if(root==NULL) return ;
          ans[level].push_back(root->val);
          print(root->left , ans , level+1);
          print(root->right , ans , level+1);

    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>ans;
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            ans.push_back(v);

        }
        print(root , ans , 0);
        return ans;

        
    }
};