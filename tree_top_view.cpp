

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
    
    if(root == NULL) return;
    
    map<int,int>mymap;
    queue<pair<Node*,int>>que;
    
    que.push({root,0});
    
    while(!que.empty()){
        
        auto curr=que.front();
        que.pop();
        
        Node* temp=curr.first;
        int horizontalDist=curr.second;
        
        if(mymap.find(horizontalDist) == mymap.end()){
            mymap[horizontalDist]=temp->data;
        }
        
        if(temp->left != NULL) que.push({temp->left,horizontalDist-1});
        
        if(temp->right != NULL) que.push({temp->right,horizontalDist+1});
        
        
    }
    
    for(auto i : mymap){
        cout<<i.second<<" ";
    }

    }

