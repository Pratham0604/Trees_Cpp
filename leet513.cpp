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
    int findBottomLeftValue(TreeNode* root) {
        
        if(root == nullptr) return 0;

        queue<TreeNode*>que;
        que.push(root);
        vector<int>ans;
       

        while(!que.empty()){

            int count=que.size();
              
            for(int i=0;i<count;i++){

                TreeNode* curr=que.front();
                que.pop();
                
                if(i == 0) ans.push_back(curr->val);

                if(curr->left != nullptr) que.push(curr->left);
                if(curr->right != nullptr) que.push(curr->right);
            }
        }

        return ans.back();
    }
};