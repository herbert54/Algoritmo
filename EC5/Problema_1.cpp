#include <iostream>
#include <string>

using namespace std;

class MyHashTable {
private:
    // Tamaño del alfabeto inglés (26 letras)
    static const int TABLE_SIZE = 26;
    int frequency[TABLE_SIZE];

public:
    // Constructor
    MyHashTable() {
        // Inicializa todas las frecuencias a 0
        for (int i = 0; i < TABLE_SIZE; i++) {
            frequency[i] = 0;
        }
    }

    // Incrementa la frecuencia de un carácter dado
    void incrementFrequency(char c) {
        int index = c - 'a';  // Convertir el carácter a índice (0 a 25)
        frequency[index]++;
    }

    // Obtiene la frecuencia de un carácter dado
    int getFrequency(char c) {
        int index = c - 'a';  // Convertir el carácter a índice (0 a 25)
        return frequency[index];
    }

    // Verifica si todas las frecuencias son iguales
    bool allFrequenciesEqual() {
        int initialFrequency = -1;

        // Recorrer el array de frecuencias
        for (int i = 0; i < TABLE_SIZE; i++) {
            // Si la frecuencia actual es 0, omitirla
            if (frequency[i] == 0) {
                continue;
            }

            // Si es la primera frecuencia encontrada
            if (initialFrequency == -1) {
                initialFrequency = frequency[i];
            } else {
                // Si una frecuencia es diferente a la inicial, no son iguales
                if (frequency[i] != initialFrequency) {
                    return false;
                }
            }
        }

        // Todas las frecuencias son iguales
        return true;
    }
};

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        // Crear una tabla hash personalizada
        MyHashTable hashTable;

        // Contar las ocurrencias de cada carácter
        for (char c : s) {
            hashTable.incrementFrequency(c);
        }

        // Verificar si todas las frecuencias son iguales
        return hashTable.allFrequenciesEqual();
    }
};

int main() {
    Solution solution;

    // Caso de prueba 1
    string s1 = "abacbc";
    bool result1 = solution.areOccurrencesEqual(s1);
    cout << "Input: '" << s1 << "' Output: " << (result1 ? "true" : "false") << endl;

    // Caso de prueba 2
    string s2 = "aaabb";
    bool result2 = solution.areOccurrencesEqual(s2);
    cout << "Input: '" << s2 << "' Output: " << (result2 ? "true" : "false") << endl;

    // Otros casos de prueba
    string s3 = "cccc";
    bool result3 = solution.areOccurrencesEqual(s3);
    cout << "Input: '" << s3 << "' Output: " << (result3 ? "true" : "false") << endl;

    string s4 = "aabbcc";
    bool result4 = solution.areOccurrencesEqual(s4);
    cout << "Input: '" << s4 << "' Output: " << (result4 ? "true" : "false") << endl;

    string s5 = "abcabc";
    bool result5 = solution.areOccurrencesEqual(s5);
    cout << "Input: '" << s5 << "' Output: " << (result5 ? "true" : "false") << endl;

    return 0;
}