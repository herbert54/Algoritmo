
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



#include <iostream>
using namespace std;

struct Nodo{
  int valor;
  int minimo;
  Nodo* next;
  Nodo(int valor,Nodo* next,int minimo):valor(valor),next(next),minimo(minimo){}
};

class MinStack {
private:
  int size_pila;
  Nodo* nodo_top;
public:
  MinStack();

  bool empty(){
    return nodo_top == NULL;
  }

  void push(int val) {
    if(empty()){
      nodo_top = new Nodo(val, nullptr, val);
    }else{
      int nuevo_minimo = (val < nodo_top->minimo) ? val : nodo_top->minimo;
      nodo_top = new Nodo(val, nodo_top,nuevo_minimo);
    }
    size_pila++;
  }

    void pop() {
        if(empty()){
          cout << "Error: Pila vacia" << endl;
          return;
        }
        Nodo* temp = nodo_top;
        nodo_top = nodo_top->next;
        delete temp;
        size_pila--;
    }

    int top() {
      if(empty()){
        cout << "Error: Pila vacia" << endl;
        return 0;
      }
      return nodo_top->valor;
    }

    int getMin() {
      if (!empty())   
        {
            return nodo_top->minimo;
        }
        return 0;
    }
};

MinStack::MinStack():nodo_top(NULL),size_pila(0){}


int main() {
  MinStack pila;
  pila.push(-2);
  pila.push(0);
  pila.push(-3);
  cout<<pila.getMin()<<endl;
  pila.pop();
  cout<<pila.top()<<endl;
  cout<<pila.getMin()<<endl;
}