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
    void solve(TreeNode* root,vector<int>v ,vector<vector<int>>&ans ,  int targetSum){
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val){
            v.push_back(root->val);
            ans.push_back(v);


        }
        return;
        }
        
        
        v.push_back(root->val);
        solve(root->left , v , ans , targetSum-(root->val));
        solve(root->right , v , ans , targetSum-(root->val));

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(root , v , ans , targetSum);
        return ans;
        
    }
};