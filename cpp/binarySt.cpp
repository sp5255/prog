#include <iostream>
using namespace std;
class BinarySearchTree
{
private:
    int data;
    BinarySearchTree *left, *right;

public:
    BinarySearchTree()
    {
        data = 0;
        left = right = nullptr;
    }

    BinarySearchTree *createNode(int);
    BinarySearchTree *buildTree(BinarySearchTree *, int);
    BinarySearchTree *max(BinarySearchTree *root);
    BinarySearchTree *search(BinarySearchTree *, int);
    void inorder(BinarySearchTree *);
    void postorder(BinarySearchTree *);
    int min(BinarySearchTree *root);
    int successor(BinarySearchTree *, int); // this is incomplete
    int predecessor(BinarySearchTree *, int);
    BinarySearchTree *deleteNode(BinarySearchTree *, int);
    BinarySearchTree *findParent(BinarySearchTree *, int);
};

BinarySearchTree *BinarySearchTree::createNode(int item)
{
    BinarySearchTree *node = new BinarySearchTree;
    node->data = item;
    node->right = node->left = nullptr;
    return node;
}

BinarySearchTree *BinarySearchTree::buildTree(BinarySearchTree *root, int item)
{
    if (!root)
        return createNode(item);
    if (root->data > item)
        root->left = buildTree(root->left, item);
    else
        root->right = buildTree(root->right, item);
    return root;
}

void BinarySearchTree::inorder(BinarySearchTree *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

void BinarySearchTree::postorder(BinarySearchTree *root)
{
    if (!root)
        return;
    postorder(root->right);
    postorder(root->right);
    cout << root->data;
}

int BinarySearchTree::min(BinarySearchTree *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

BinarySearchTree *BinarySearchTree::max(BinarySearchTree *root)
{
    while (root->right != nullptr)
        root = root->right;
    return root;
}

BinarySearchTree *BinarySearchTree::search(BinarySearchTree *root, int key)
{
    if (!root || root->data == key)
        return root;
    if (root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

/* int BinarySearchTree::successor(BinarySearchTree* root, int key) {
    if (root->right != nullptr)
        return min(root->right);

} */

BinarySearchTree *BinarySearchTree::findParent(BinarySearchTree *root, int key)
{
    BinarySearchTree *parent = nullptr;
    while (root && root->data != key)
    {
        if (root->data > key)
        {
            parent = root;
            root = root->left;
        }
        else
        {
            parent = root;
            root = root->right;
        }
    }
    // cout<<"parent : "<<parent->data;
    return parent;
}

BinarySearchTree *BinarySearchTree::deleteNode(BinarySearchTree *root, int key)
{
    BinarySearchTree *found = search(root, key), *p;
    
    if(!found){
        cout<<"Node doesn't exist\n";
        return found;
    }


    // if node has both the childrens

    if (found->right && found->left)
    {

        BinarySearchTree *largest = max(found->left);       //find largest element in left subtree of current node
        p = findParent(root, largest->data);                // find parent of the largest node because we have to delete the largest element after copy it to the node to be deleted
        found->data = largest->data;                           // copy the largest element of left subtree to the node to be deleted

        // if largest node present in the left of its parent then makes the left child null of current parent of largest otherwise assighn null to the right
        if (largest == p->left)
        {
            p->left = nullptr;
        }

        else if (largest == p->right)
        {
            p->right = nullptr;
        }

        //now  delete assigned memeory to largest
        largest = nullptr;
        free(largest);
    }

    // when node has one child

    else if (found->right || found->left)
    {

        // now just find out the child of the node and assign that child to the parent of currnent node(means the node that to be deleted)
        p = findParent(root, found->data);

        if (p->left == found)
        {
            if (found->right)
            {
                p->left = found->right;
            }

            else
            {
                p->left = found->left;
            }
            found = nullptr;
            free(found);
        }
        else if (p->right == found)
        {

            if (found->right)
                p->right = found->right;
            else
                p->right = found->left;

            found = nullptr;
            free(found);
        }
    }

        // when node has no child 

    else if (!found->left && !found->right)
    {
       p = findParent(root, key); 

        //simply assing null to the parents of current node(i.e, node to be deleted)
        if (p->left == found)
        {
            p->left = NULL;
        }

        if (p->right == found)
        {
            p->right = NULL;
        }

        free(found);     
    }
    return found;
}

int main()
{

    BinarySearchTree b, *root = nullptr;
   /*   cout << "Enter the numbers of node\n";
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Enter suitable number of nodes\n";
        return 1;
    }
    else {
        cout << "Enter the data\n";
        int item;
        cin >> item;
        root = b.buildTree(root, item);
        for (int i = 0; i < n - 1; i++) {
            cin >> item;
            b.buildTree(root, item);
        }
 */
      /*   cout << "Inorder\n";
        b.inorder(root);

        cout << "\nEnter key to search\n";
        int k;
        cin >> k;
        BinarySearchTree* f;
        f = b.search(root, k);
        if (!f)
            cout << "not found\n";
        else
            cout << "found\n";

        cout << "succesor : " << b.successor(f, k) << endl; */


    /* int min = b.min(root);
        cout << "\nminimum element is : " << min<<endl; */

  /*   }
    cout << endl; */

   /*  root = b.buildTree(root, 8);9
    b.buildTree(root, 5);
    b.buildTree(root, 3);
    b.buildTree(root, 4);
    b.buildTree(root, 1);
    b.buildTree(root, 6);
    b.buildTree(root, 7);
    b.buildTree(root, 9);
    b.buildTree(root, 10); */

    cout << "Tree\n";
    b.inorder(root);

    int k;
    cout << "enter key to delete\n";
    cin >> k;
    //BinarySearchTree *f;
    b.deleteNode(root, k);

    cout << "After delete\n";
    b.inorder(root);
    cout << endl;
    return 0;
}