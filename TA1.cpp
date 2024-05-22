#include <iostream>
#include <math.h>
using namespace std;
template<typename T>
struct Nodo
{
    T data;
    Nodo* next;
};

template<typename T>
class List{
    private:
    Nodo<T>* head;
    public: 
    List():head(nullptr){}

    List(List<T>& other) {
        head = nullptr;
        Nodo<T>* temp = other.head;
        while (temp != nullptr) {
            push_back(temp->data);
            temp = temp->next;
        }
    }

        ~List() {
        while (head != nullptr) {
            pop_front();
        }
    }

        // Retorna el elemento al comienzo
        T front(){
                return head->data;
        }

        // Retorna el elemento al final
        T back(){
            Nodo<T>* temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            return temp->data;
        }

        //Agrega elemento al comienzo
        void push_front(T ndata){
            Nodo<T>* nodo=new Nodo<T>;
            nodo->data=ndata;
            nodo->next=head;
            head=nodo;
        }
        //Agrega elemento al final
        void push_back(T ndata){
            Nodo<T>* nodo=new Nodo<T>;
            nodo->data=ndata;
            nodo->next = nullptr; // Asegurarse de que el nodo que estamos agregando sea el último nodo

            if (head==nullptr)
            {
                head=nodo;// Si la lista está vacía, el nuevo nodo se convierte en la cabeza
            }else
            {
                Nodo<T>* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = nodo;
            }     
        }

        // Remueve el elemento al comienzo
        T pop_front(){
            T data=head->data;
            Nodo<T>* temp=head;
            head=head->next;
            delete temp;
            return data;
        }

        // Remueve el elemento al final
        T pop_back(){
            if (head->next==NULL)
            {
                T data=head->data;
                delete head;
                head=nullptr;
                return data;
            }else
            {
                Nodo<T>* temp=head;
                while (temp->next->next!=NULL)
                {
                    temp=temp->next;
                }
                T data = temp->next->data;
                delete temp->next;
                temp->next=NULL;
                return data;
            } 
        }

        // Retorna el elemento en la posición indicada
        T operator[](int pos){
            Nodo<T>* temp=head;
            int i=0;
            T elemt;
            while (i<pos-1)
            {
                temp=temp->next;
                elemt=temp->data;
                i++;
            }
            return elemt;
        };

        // Retorna si la lista está vacía o no
        bool empty(){
            Nodo<T>* temp=head;
            if (temp==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        // Retorna el tamaño de la lista
        int size(){
            Nodo<T>* temp=head;
            int counter=0;
            while (temp!=NULL)
            {
                temp=temp->next;
                counter++;
            }
            return counter;
        }

        // Elimina todos los elementos de la lista
        void clear(){
            while (head!=NULL)
            {
                Nodo<T>* temp=head;
                head=head->next;
                delete temp;
            } 
        }

        void sort() {
        if (head == nullptr || head->next == nullptr){
            return; // No hay necesidad de ordenar si la lista está vacía o tiene solo un elemento
        }
        Nodo<T>* current = head;
        while (current->next != nullptr) {
            Nodo<T>* minNode = current;
            Nodo<T>* temp = current->next;
            while (temp != nullptr) {
                if (temp->data < minNode->data) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            T tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;

            current = current->next;
            }
        }

        // Revierte la lista
        void reverse(){
            Nodo<T>* prev=NULL;
            Nodo<T>* nxt=NULL;
            while (head!=NULL)
            {
                nxt=head->next;  
                head->next=prev; 
                prev=head;      
                head=nxt;      
            }
            head=prev;       
        }

        void print() {
        Nodo<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
        }

        /*LAB 2*/

        void binari_decimal(){
            Nodo<int>* temp1=head;
            int size=0;
            while (temp1->next!=nullptr){
               temp1=temp1->next; 
               size++;
            }

            Nodo<int>* temp2=head;
            int num=0;
            while (temp2!=nullptr)
            {
                num+=temp2->data*pow(2,size);
                temp2=temp2->next;
                size--;
            }
            cout<<"El numero en base 10 es: "<<num<<endl;
        }

        void media(){
            if (head==nullptr){
                cout << "La lista está vacía" <<endl;
            }
            
            Nodo<T>* slow = head;
            Nodo<T>* fast = head;
            Nodo<T>* prev_slow = nullptr;

            // Mover 'fast' dos pasos y 'slow' un paso hasta que 'fast' llegue al final
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                prev_slow = slow;
                slow = slow->next;
            }

            // Si la longitud de la lista es par, selecciona el segundo nodo en el medio
            if (fast == nullptr) {
                slow = prev_slow->next;
            }

            // 'slow' apunta al nodo en el punto medio
            cout << "Elementos desde el medio hasta el final: ";
            while (slow != nullptr) {
                std::cout << slow->data << " ";
                slow = slow->next;
            }
        }

        Nodo<T>* get_head() const {
        return head;
    }

        static List<T> merge_sorted_lists(List<T>& list1,List<T>& list2) {
        List<T> merged_list;
        Nodo<T>* current1 = list1.head;
        Nodo<T>* current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data <= current2->data) {
                merged_list.push_back(current1->data);
                current1 = current1->next;
            } else {
                merged_list.push_back(current2->data);
                current2 = current2->next;
            }
        }

        // Agregar los elementos restantes de la lista 1
        while (current1 != nullptr) {
            merged_list.push_back(current1->data);
            current1 = current1->next;
        }

        // Agregar los elementos restantes de la lista 2
        while (current2 != nullptr) {
            merged_list.push_back(current2->data);
            current2 = current2->next;
        }

        return merged_list;
    }
};


int main(){
    // List<int> lista;
    // lista.push_back(1);
    // lista.push_back(2);
    // lista.push_back(3);
    // lista.push_back(4);
    // lista.push_back(5);
    // lista.push_back(6);
    // lista.print();
    // lista.media();
    //lista.binari_decimal();


    // Crear dos listas ordenadas
    List<int> lista1;
    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(4);

    List<int> lista2;
    lista2.push_back(1);
    lista2.push_back(3);
    lista2.push_back(4);

    // Unir las listas ordenadas
    List<int> merged_list = List<int>::merge_sorted_lists(lista1, lista2);

    // Imprimir la lista unida
    Nodo<int>* current = merged_list.get_head();
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

}


