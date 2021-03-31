// implement searching

#include<iostream>
using namespace std;

class Bst {
private:
    int data;
    Bst* left, * right;
public:
    Bst* createNode(int );
    Bst* build(Bst*, int);
    void inorder(Bst*);
    Bst* search(Bst*, int);
    Bst* Rsearch(Bst*, int);        //Recursive search
};
Bst* Bst::createNode(int item) {
    Bst* temp = new Bst;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

Bst* Bst::build(Bst* root, int item) {
    if (!root) {
        root = createNode(item);
        return root;
    }
        //return createNode(item);
    if (root->data > item)
        root->left = build(root->left, item);
    else if (root->data <= item)
        root->right = build(root->right, item);

    return root;
}

void Bst::inorder(Bst* temp) {
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << "\t";
    inorder(temp->right);
}

Bst* Bst::search(Bst* root, int key) {
    while (root != NULL && root->data != key) {
        if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

Bst* Bst::Rsearch(Bst* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return Rsearch(root->left, key);
    //if (key >= root->data)
    else
        return Rsearch(root->right, key);
}

int main() {
    Bst b, * rt = NULL;
    int n;
    cout << "Enter the number of Nodes\n";
    cin >> n;
    int el;
    cout << "Enter Nodes\n";
    cin >> el;
    rt = b.build(rt, el);
    for (int i = 0; i < n - 1; i++) {
        cin >> el;
        b.build(rt, el);
    }
/* 
    rt = b.build(rt, 8);
    b.build(rt, 5);
    b.build(rt, 3);
    b.build(rt, 4);
    b.build(rt, 1);
    b.build(rt, 6);
    b.build(rt, 7);
    b.build(rt, 9);
    b.build(rt, 10); */
    
    cout << "inoerder\n";
    b.inorder(rt);
    
    cout << endl;
    
   /*  int key;
    cout << "enter the element you want to search\n";
    cin >> key; */
    /* int f;
    
    f = b.search(rt, key); 

    if (f >= 0)
        cout << "key found\n";
    else
        cout << "not found\n"; */
    /* Bst* p;
    //   p = b.Rsearch(rt, key);
    p = b.search(rt, key);
    if (p == nullptr)
        cout << "not found";
    else
        cout << "found";
    cout << endl;
    return  0; */
}