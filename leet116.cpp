/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       
       if(root == nullptr) return nullptr;

       queue<Node*>que;
       que.push(root);

       while(!que.empty()){

          int count=que.size();
          Node* last=nullptr;

          for(int i=0;i<count;i++){

            auto node=que.front();
            que.pop();

            node->next=last;
            last=node;

          if(node->right != nullptr) que.push(node->right);
          if(node->left != nullptr) que.push(node->left);
          }
       } 
       return root;
    }
};