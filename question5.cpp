#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;
    Node* current = head;
    
    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return true;
        }
        visited.insert(current);
        current = current->next;
    }
    
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    
    if (hasCycle(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}