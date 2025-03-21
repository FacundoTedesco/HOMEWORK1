#include <iostream>
#include <chrono>

// Función recursiva constexpr 
constexpr bool comparaConstexpr(const char* str1, const char* str2) {
  if (*str1 != *str2) {  
      return false;  
  }
  if (*str1 == '\0') {  
      return true;  
  }
  return comparaConstexpr(str1 + 1, str2 + 1);  
}

// Función del a y b para comparación en tiempo de ejecución
bool sonIguales(const char* str1, const char* str2) {
    if (*str1 != *str2) return false;
    if (*str1 == '\0') return true;
    return sonIguales(str1 + 1, str2 + 1);
}

int main() {
    constexpr const char* texto1 = "Soy Facundo Tedesco estoy cursando 4 materias y este trabajo es para Paradigmas de Programación.";
    constexpr const char* texto2 = "Soy Facundo Tedesco estoy cursando 4 materias y este trabajo es para Paradigmas de Programación.";
    constexpr const char* texto3 = "Soy Facundo Tedesco estoy haciendo 4 materias y este trabajo es para Fisica";

    // Compara compilación
    constexpr bool resultadoConstexpr = comparaConstexpr(texto1, texto2);

    // Medir tiempo de ejecución con enunciado (debería ser igual)
    auto startTime = std::chrono::high_resolution_clock::now();
    bool resultadoRuntime = sonIguales(texto1, texto2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "Comparación en tiempo de compilación: " << (resultadoConstexpr ? "Iguales" : "Diferentes") << std::endl;
    std::cout << "Comparación en tiempo de ejecución: " << (resultadoRuntime ? "Iguales" : "Diferentes") 
              << " - Tiempo: " << elapsedTime.count() << " NanoS" << std::endl;

    return 0;
}

/*
CONCLUSIÓN:
La comparación realizada con `constexpr` se mide en tiempo de compilación 100%, 
por lo que no tiene un costo de ejecución en `main()`. Esto significa que el tiempo 
de ejecución de `comparaConstexpr` es **cero** en tiempo de ejecución.
En cambio, `sonIguales` sí se ejecuta en tiempo de ejecución, consumiendo 
un tiempo que dependerá del tamaño de la cadena y la eficiencia de la CPU.
Esto demuestra la ventaja de `constexpr` para operaciones inmutables conocidas en compilación.
*/

