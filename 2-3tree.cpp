#include <iostream>
using namespace std;

class Node {
public:
    int data[2];     
    Node* child[3];  
    int n;           

    Node() {
        n = 0;
        for (int i = 0; i < 3; i++)
            child[i] = NULL;
    }
};

class TwoThreeTree {
private:
    Node* root;

    Node* insert(Node* node, int key, int &upKey) {
        if (node == NULL) {
            Node* newNode = new Node();
            newNode->data[0] = key;
            newNode->n = 1;
            return newNode;
        }

        if (node->child[0] == NULL) {
            if (node->n == 1) {
                if (key < node->data[0]) {
                    node->data[1] = node->data[0];
                    node->data[0] = key;
                } else {
                    node->data[1] = key;
                }
                node->n = 2;
                return NULL;
            } else {
                int temp[3];
                temp[0] = node->data[0];
                temp[1] = node->data[1];
                temp[2] = key;

                for (int i = 0; i < 3; i++)
                    for (int j = i+1; j < 3; j++)
                        if (temp[i] > temp[j])
                            swap(temp[i], temp[j]);

                Node* newNode = new Node();
                node->data[0] = temp[0];
                node->n = 1;

                newNode->data[0] = temp[2];
                newNode->n = 1;

                upKey = temp[1];
                newNode->child[0] = newNode->child[1] = NULL;

                return newNode;
            }
        }

        int pos;
        if (key < node->data[0])
            pos = 0;
        else if (node->n == 1 || key < node->data[1])
            pos = 1;
        else
            pos = 2;

        int newKey;
        Node* newChild = insert(node->child[pos], key, newKey);

        if (newChild == NULL)
            return NULL;

        if (node->n == 1) {
            if (pos == 0) {
                node->data[1] = node->data[0];
                node->data[0] = newKey;
                node->child[2] = node->child[1];
                node->child[1] = newChild;
            } else {
                node->data[1] = newKey;
                node->child[2] = newChild;
            }
            node->n = 2;
            return NULL;
        } else {
            int tempKeys[3];
            Node* tempChild[4];

            tempKeys[0] = node->data[0];
            tempKeys[1] = node->data[1];
            tempKeys[2] = newKey;

            tempChild[0] = node->child[0];
            tempChild[1] = node->child[1];
            tempChild[2] = node->child[2];
            tempChild[3] = newChild;

            for (int i = 0; i < 3; i++)
                for (int j = i+1; j < 3; j++)
                    if (tempKeys[i] > tempKeys[j])
                        swap(tempKeys[i], tempKeys[j]);

            Node* newNode = new Node();

            node->data[0] = tempKeys[0];
            node->n = 1;

            newNode->data[0] = tempKeys[2];
            newNode->n = 1;

            upKey = tempKeys[1];

            return newNode;
        }
    }

    void inorder(Node* node) {
        if (node == NULL) return;

        if (node->n == 1) {
            inorder(node->child[0]);
            cout << node->data[0] << " ";
            inorder(node->child[1]);
        } else {
            inorder(node->child[0]);
            cout << node->data[0] << " ";
            inorder(node->child[1]);
            cout << node->data[1] << " ";
            inorder(node->child[2]);
        }
    }

public:
    TwoThreeTree() {
        root = NULL;
    }

    void insert(int key) {
        int upKey;
        Node* newChild = insert(root, key, upKey);

        if (newChild != NULL) {
            Node* newRoot = new Node();
            newRoot->data[0] = upKey;
            newRoot->n = 1;
            newRoot->child[0] = root;
            newRoot->child[1] = newChild;
            root = newRoot;
        }
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    TwoThreeTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);

    cout << "Inorder traversal:\n";
    tree.display();

    return 0;
}



