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
    int maxDepth(TreeNode* root) {
        int result = 0;

        dfs(root, 0, result);

        return result;


    }

    void dfs(TreeNode* root, int height, int &result){
        if(root){
            if(root->left){
                dfs(root->left , height+1 , result);
            }

            if(root->right){
                dfs(root->right, height+1 , result);
            }

            result = max(result, height+1);
        }

        return;
    }
};
