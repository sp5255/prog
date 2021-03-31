#include<iostream>
#include<queue>
using namespace std;

class Tree {
private:
    int data;
    Tree* root, * left, * right, * currentParent;
    queue<Tree*> q;
public:
    Tree* makeTree(int arr[], int size) {
        root = new Tree;
        q.push(root);
        root->data = arr[0];

        int count = 0;
        while (count < size - 1) {
            currentParent = q.front();
            q.pop();

            left = new Tree;
            q.push(left);

            left->data = arr[++count];
            currentParent->left = left;

            right = new Tree;
            q.push(right);
            right->data = arr[++count];
            currentParent->right = right;
        }
        return root;
    }

    void preorder(Tree* start) {
        if (start == NULL)
            return;
        cout << start->data << "\t";
        preorder(start->left);
        preorder(start->right);
    }

    void inorder(Tree* start) {
        if (start == NULL)
            return;
        inorder(start->left);
        cout << start->data << "\t";
        inorder(start->right);
    }

    void postorder(Tree* start) {
        if (start == NULL)
            return;
        postorder(start->left);
        postorder(start->right);
        cout << start->data << "\t";
    }
};

int main() {
    int arr[] = { 32,5,8,22,6,12,21 };

    int size = sizeof(arr) / sizeof(int);

    Tree t, * root;
    root = t.makeTree(arr, size);

    cout << "preorder\n";
    t.preorder(root);
    cout << "\ninorder\n";
    t.inorder(root);
    cout << "\npostorder\n";
    t.postorder(root);
    cout << endl;
}
