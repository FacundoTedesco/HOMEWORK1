#include <iostream>
#include <chrono>

bool sonIguales(const char* str1, const char* str2) {
    if (*str1 != *str2) return false;
    if (*str1 == '\0') return true;
    return sonIguales(str1 + 1, str2 + 1);
}

int main() {
    const char* texto1 = "Soy Facundo Tedesco estoy cursando 4 materias y este trabajo es para Paradigmas de Programación.";
    const char* texto2 = "Soy Facundo Tedesco estoy cursando 4 materias y este trabajo es para Paradigmas de Programación.";
    const char* texto3 = "Soy Facundo Tedesco estoy haciendo 4 materias y este trabajo es para Fisica";

    // Medir tiempo de ejecución con enunciado (debería ser igual)
    auto startTime = std::chrono::high_resolution_clock::now();
    bool resultado1 = sonIguales(texto1, texto2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    
    std::cout << "Comparación 1: " << (resultado1 ? "Iguales" : "Diferentes") 
              << " - Tiempo: " << elapsedTime.count() << " NanoS" << std::endl;

    // Medir tiempo de ejecución con enunciado (debería ser diferente)
    startTime = std::chrono::high_resolution_clock::now();
    bool resultado2 = sonIguales(texto1, texto3);
    endTime = std::chrono::high_resolution_clock::now();
    elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    
    std::cout << "Comparación 2: " << (resultado2 ? "Iguales" : "Diferentes") 
              << " - Tiempo: " << elapsedTime.count() << " NanoS" << std::endl;

    return 0;
}