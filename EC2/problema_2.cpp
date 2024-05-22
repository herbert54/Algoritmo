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
 
int mcd(int a,int b){
    if (b==0)
    {
        return a;
    }else
    {
        return mcd(b,a%b);
    }
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        if (head == nullptr || head->next == nullptr) { // Si hay cero o un solo nodo, retornar la lista original
            return head;
        }
        int v;
        while (temp!=nullptr && temp->next!=nullptr)
        {
            v=mcd(temp->val,temp->next->val);
            ListNode* nodo= new ListNode(v);
            nodo->next=temp->next;
            temp->next=nodo;
            temp=temp->next->next;
        }

        return head;
    }

};

int main() {
    ListNode* head = new ListNode(18);
    // head->next = new ListNode(6);
    // head->next->next = new ListNode(10);
    // head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next = new ListNode(6);

    Solution solution;
    ListNode* result = solution.insertGreatestCommonDivisors(head);
    ListNode* temp = result;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

}