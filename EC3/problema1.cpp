
// Definition for a Node.
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childTail = flatten(curr->child);
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                childTail->next = nextNode;
                if (nextNode) nextNode->prev = childTail;
            }
            if (!curr->next) break;
            curr = curr->next;
        }

        return head;
    }
};

// Función de utilidad para imprimir la lista aplanada
void printFlattenedList(Node* head) {
    cout << "Lista aplanada: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Crear nodos
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    Node* node11 = new Node(11);

    // Establecer relaciones
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;
    node3->child = node7;
    node7->next = node8;
    node8->prev = node7;
    node8->next = node9;
    node9->prev = node8;
    node9->next = node10;
    node10->prev = node9;
    node8->child = node11;

    Solution solution;
    head = solution.flatten(head);
    printFlattenedList(head);

    // Liberar memoria
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
