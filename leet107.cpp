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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
       deque<vector<int>>dq;

        if(root == NULL) return {};

        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty()){
            int count=que.size();
            vector<int> row;

            for(int i=0;i<count;i++){

                TreeNode* temp=que.front();
                que.pop();

                row.push_back(temp->val);

                if(temp->left != NULL) que.push(temp->left);
                if(temp->right != NULL) que.push(temp->right);
                
            }
           dq.push_front(row);
        }

        return vector<vector<int>>(dq.begin(),dq.end());
    }
};