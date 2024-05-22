// #include <iostream>
// #include <stack>
// #include <string>

// bool esOperador(char c) {
//     return c == '+' || c == '-' || c == '*' || c == '/';
// }

// bool validarOperacionAritmetica(const std::string& operacion) {
//     std::stack<char> pila;

//     for (char c : operacion) {
//         if (c == '(') {
//             pila.push(c);
//         } else if (c == ')') {
//             if (pila.empty() || pila.top() != '(') {
//                 return false; // Error: paréntesis no balanceados
//             }
//             pila.pop();
//         } else if (esOperador(c)) {
//             if (pila.empty() || !esOperador(pila.top())) {
//                 return false; // Error: operador sin operandos
//             }
//             pila.pop(); // Eliminamos el operador anterior
//         } else if (std::isdigit(c)) {
//             if (!pila.empty() && std::isdigit(pila.top())) {
//                 return false; // Error: número sin operador
//             }
//         } else if (c != ' ') {
//             return false; // Caracter no válido
//         }
//     }

//     return pila.empty(); // Si la pila está vacía, la operación es válida
// }

// int main() {
//     std::string operacion;

//     std::cout << "Ingrese la operacion aritmetica: ";
//     std::getline(std::cin, operacion); // Usamos getline para leer la línea completa

//     if (validarOperacionAritmetica(operacion)) {
//         std::cout << "La operacion es valida." << std::endl;
//     } else {
//         std::cout << "La operacion contiene un error." << std::endl;
//     }

//     return 0;
// }


#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>

bool validar_expresion(const std::string& expresion) {
    std::stack<char> pila;
    std::unordered_set<char> operadores {'+', '-', '*', '/'};
    
    for (size_t i = 0; i < expresion.length(); ++i) {
        char c = expresion[i];
        if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            if (pila.empty() || pila.top() != '(') {
                return false;
            }
            pila.pop();
        } else if (operadores.find(c) != operadores.end()) {
            if (pila.empty() || (operadores.find(pila.top()) == operadores.end() && pila.top() != '(')) {
                return false;
            }
            pila.push(c);
        } else if (isdigit(c)) {
            // Avanzar al siguiente operador o paréntesis
            while (i + 1 < expresion.length() && isdigit(expresion[i + 1])) {
                ++i;
            }
        }
    }
    
    return pila.empty();
}

int main() {
    std::vector<std::string> expresiones = {
        "5 + 8 / 2",
        "(7 + 8) / 2",
        "(14 + 7) / (5 + 2)",
        "(3 * 2 + 8) / (10 - 5 + 2) * 12",
        "(6 + 8) / (5 + 2) * 3 +",
        "(6 + 8) 10 / (5 + 2) * 3 +",
        "(6 + 8 -) 10 / (5 + 2) * 3 )"
    };

    for (const std::string& expresion : expresiones) {
        std::cout << expresion << ": " << (validar_expresion(expresion) ? "true" : "false") << std::endl;
    }

    return 0;
}