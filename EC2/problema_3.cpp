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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;

        if (head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        int pre;
        while (temp!=nullptr && temp->next!=nullptr)
        {
            pre=temp->val;
            temp->val=temp->next->val;
            temp->next->val=pre;
            temp=temp->next->next;
        }
        return head;
        
    }
};


int main() {
    // Crear una lista de ejemplo
    ListNode* head = new ListNode();
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);


    Solution solution;

    ListNode* result = solution.swapPairs(head);

    // Imprimir la lista resultante
    ListNode* temp = result;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

}