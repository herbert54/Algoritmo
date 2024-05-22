#include <iostream>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
      int val;
   ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while (head!=nullptr && head->val==val)
        {
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};


int main() {
    // Crear una lista de ejemplo
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    // Crear una instancia de la clase Solution
    Solution solution;

    // Llamar al método removeElements para eliminar todos los nodos con valor 6
    int valToRemove = 6;
    ListNode* result = solution.removeElements(head, valToRemove);

    // Imprimir la lista resultante
    ListNode* temp = result;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

}