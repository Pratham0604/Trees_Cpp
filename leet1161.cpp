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
    int maxLevelSum(TreeNode* root) {
        
       queue<TreeNode*> que;
       que.push(root);

      // int maxSum=INT_MIN;
       vector<int>res;

       while(!que.empty()){
           
           int count=que.size();
           int sum=0;

           for(int i=0;i<count;i++){
              
              TreeNode* curr=que.front();
              que.pop();

              sum += curr->val;

              if(curr->left) que.push(curr->left);
              if(curr->right) que.push(curr->right);
           }
          res.push_back(sum);
           //maxSum=max(maxSum,sum);
          
       }
       int maxsum=INT_MIN;   // initializing it as INT_MIN to handle negative values
        int idx;
       for(int i=0;i<res.size();i++){
              if(res[i] > maxsum){
                maxsum=res[i];
                idx=i;
              }
       }
       return idx+1;
    }
};