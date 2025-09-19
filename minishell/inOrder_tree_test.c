
// Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


void ft_fill_res(int res[], int val);

// You just need to modify res array such that
// it contains inorder traversal
void inOrder(struct Node* root, int res[]) {
    // code here
    if (!root)
        return ;
    if (root->left)
        inOrder(root->left, res);
    if (!root->left && !root->right)
    {
        ft_fill_res(res, root->data);
        return ;
    }
    if (root->right)
    {
        ft_fill_res(res, root->data);
        inOrder(root->right, res);
        return ;
    }
        
}

void ft_fill_res(int res[], int val)
{
    static int i = 0;
    
    res[i] = val;
    i++;
}

// void inOrder(struct Node* root, int res[]) {
//     if (!root)
//         return;
    
//     inOrder(root->left, res);      // left
//     ft_fill_res(res, root->data);  // visit
//     inOrder(root->right, res);     // right
// }




