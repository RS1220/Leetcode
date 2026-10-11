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
    unordered_map<int ,int>mp;
    int maxD=0;

    void depth(TreeNode* root , int d){
        if(root==NULL) return;
        maxD=max(maxD , d);
        mp[root->val]=d;
        depth(root->left ,  d+1);
        depth(root->right , d+1);


    }

    TreeNode* lca(TreeNode* root){
        if(root==NULL || mp[root->val]==maxD) return root;

        TreeNode* leftN=lca(root->left);
        TreeNode* rightN=lca(root->right);

        if(leftN && rightN) return root;
        return leftN!=NULL?leftN:rightN;
    }



    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        depth(root  , 0);
        return lca(root);
    }
};