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
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left) , level(root->right));
    }
     void printLR(TreeNode* root , int curr , int required , vector<int>&v){
        if(root==NULL) return ;
        if(curr==required){
            v.push_back(root->val);
            return;

        }
        printLR(root->left , curr+1 , required , v);
        printLR(root->right , curr+1 , required , v);


     }
     void printRL(TreeNode* root , int curr , int required , vector<int>&v){
        if(root==NULL) return ;
        if(curr==required){
            v.push_back(root->val);
            return;

        }
        printRL(root->right , curr+1 , required , v);
        printRL(root->left, curr+1 , required , v);


     }
    void levelOrder(TreeNode* root , vector<vector<int>>& ans){

        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            if(i%2==0){
                printRL(root ,1,i,v );
            }
            else printLR(root ,1,i,v );

            ans.push_back(v);
        }


    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrder(root , ans);
        return ans;
        
    }
};