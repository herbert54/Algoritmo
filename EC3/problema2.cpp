#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void moveToFront(Node* node) {
        removeNode(node);
        addToHead(node);
    }
    
    void evictLRU() {
        Node* lru = tail->prev;
        removeNode(lru);
        cache.erase(lru->key);
        delete lru;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity), head(new Node(-1, -1)), tail(new Node(-1, -1)) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToFront(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (cache.size() == capacity) {
                evictLRU();
            }
            Node* newNode = new Node(key, value);
            addToHead(newNode);
            cache[key] = newNode;
        }
    }
    
    ~LRUCache() {
        delete head;
        delete tail;
        for (auto& pair : cache) {
            delete pair.second;
        }
    }
};



int main() {
    // Crear una instancia de LRUCache con capacidad 2
    LRUCache lRUCache(2);

    // Agregar algunos elementos y realizar operaciones
    lRUCache.put(1, 1); // cache es {1=1}
    lRUCache.put(2, 2); // cache es {1=1, 2=2}
    cout << "Valor de la clave 1: " << lRUCache.get(1) << endl; // debería devolver 1
    lRUCache.put(3, 3); // LRU clave fue 2, evicta clave 2, cache es {1=1, 3=3}
    cout << "Valor de la clave 2: " << lRUCache.get(2) << endl; // debería devolver -1 (no encontrado)
    lRUCache.put(4, 4); // LRU clave fue 1, evicta clave 1, cache es {4=4, 3=3}
    cout << "Valor de la clave 1 despues de evictar: " << lRUCache.get(1) << endl; // debería devolver -1 (no encontrado)
    cout << "Valor de la clave 3: " << lRUCache.get(3) << endl; // debería devolver 3
    cout << "Valor de la clave 4: " << lRUCache.get(4) << endl; // debería devolver 4

    return 0;
}
