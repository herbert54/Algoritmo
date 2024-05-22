#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <unordered_set>
using namespace std;

class AllOne {
private:
    unordered_map<string, int> counts; // Mapa para almacenar los recuentos de las cadenas
    map<int,unordered_set<string>> countToKeys; // Mapa para almacenar las cadenas por recuento
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int count = ++counts[key];
        countToKeys[count].insert(key);
        if (count > 1) countToKeys[count - 1].erase(key);
        if (countToKeys[count - 1].empty()) countToKeys.erase(count - 1);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        int count = --counts[key];
        if (count == 0) counts.erase(key);
        else {
            countToKeys[count].insert(key);
            countToKeys[count + 1].erase(key);
            if (countToKeys[count + 1].empty()) countToKeys.erase(count + 1);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (countToKeys.empty()) return "";
        return *(countToKeys.rbegin()->second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (countToKeys.empty()) return "";
        return *(countToKeys.begin()->second.begin());
    }
};


int main() {
    // Crear una instancia de la clase AllOne
    AllOne allOne;

    // Insertar algunas claves y aumentar sus valores
    allOne.inc("apple");
    allOne.inc("banana");
    allOne.inc("apple");
    allOne.inc("banana");
    allOne.inc("apple");
    allOne.inc("orange");

    // Mostrar la clave con el valor máximo y mínimo
    cout << "Clave con el valor maximo: " << allOne.getMaxKey() << endl;
    cout << "Clave con el valor minimo: " << allOne.getMinKey() << endl;

    // Decrementar valores de algunas claves
    allOne.dec("banana");
    allOne.dec("banana");

    // Mostrar la clave con el valor máximo y mínimo después de decrementar
    cout << "Clave con el valor maximo despues de decrementar: " << allOne.getMaxKey() << endl;
    cout << "Clave con el valor minimo despues de decrementar: " << allOne.getMinKey() << endl;

    return 0;
}
