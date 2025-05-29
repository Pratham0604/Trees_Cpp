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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        if(root == NULL) return ans;

       // vector<int>row;

        queue<TreeNode*>que;
        stack<int>stk;
        bool reverse=false;

        que.push(root);

        while(!que.empty()){
            
            vector<int>row;
            int count=que.size();

            for(int i=0;i<count;i++){

             TreeNode* curr=que.front();
             que.pop();

             if(reverse) stk.push(curr->val);
             else row.push_back(curr->val);

             if(curr->left != NULL) que.push(curr->left);
             if(curr->right != NULL) que.push(curr->right);

            }

            if(reverse){
                while(!stk.empty()){
                    row.push_back(stk.top());
                    stk.pop();
                }
            }

            reverse = !reverse;
            ans.push_back(row);

        }
        return ans;
    }
};