#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool hasDuplicates(Node* root, unordered_set<int>& seen) {
    if (root == nullptr) return false;
    
    if (seen.find(root->data) != seen.end()) {
        return true;
    }
    
    seen.insert(root->data);
    
    return hasDuplicates(root->left, seen) || hasDuplicates(root->right, seen);
}

bool checkDuplicates(Node* root) {
    unordered_set<int> seen;
    return hasDuplicates(root, seen);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    
    if (checkDuplicates(root)) {
        cout << "Duplicates Found" << endl;
    } else {
        cout << "No Duplicates" << endl;
    }
    
    return 0;
}