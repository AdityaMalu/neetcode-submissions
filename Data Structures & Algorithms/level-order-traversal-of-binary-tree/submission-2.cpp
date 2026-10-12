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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> index;
        vector<vector<int>> ans;

        queue<pair<TreeNode*,int>> q;


        if(!root) return {};

        q.push({root, 0});

        while(!q.empty()){
            pair<TreeNode* , int> curr = q.front();
            q.pop();
            TreeNode* currNode = curr.first;
            int level = curr.second;

            if(index.count(level)){
                index[level].push_back(currNode->val);
            }
            else{
                index[level] = {currNode->val};
            }

            if(currNode->left){
                q.push({currNode->left, level+1});
            }

            if(currNode->right){
                q.push({currNode->right , level+1});
            }
        }


        for(auto i : index){
            ans.push_back(i.second);
        }
        // reverse(ans.begin() , ans.end());
        return ans;
    }
};
