#include <iostream>

bool sonIguales(const char* str1, const char* str2) {
    if (*str1 != *str2) return false;  
    if (*str1 == '\0') return true;    
    return sonIguales(str1 + 1, str2 + 1); 
}

int main() {
    const char* texto1 = "Soy Facundo Tedesco estoy cursando 4 materias y este trabajo es para Paradigmas de Programación.";
    const char* texto2 = "Soy Facundo Tedesco estoy cursando 4 materias y este trabajo es para Paradigmas de Programación.";
    const char* texto3 = "Soy Facundo Tedesco estoy haciendo 4 materias y este trabajo es para Fisica";

    std::cout << "Comparación 1: " << (sonIguales(texto1, texto2) ? "Iguales" : "Diferentes") << std::endl;
    std::cout << "Comparación 2: " << (sonIguales(texto1, texto3) ? "Iguales" : "Diferentes") << std::endl;

    return 0;
}
