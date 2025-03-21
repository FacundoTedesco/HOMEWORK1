#include <iostream>
#include <fstream>
#include <string>
#include "ejercicio2.h"

using namespace std;

// Escribir mensajes en el log
void logMessage(const string& mensaje, const string& nivelSeveridad) {
    ofstream logFile("log.txt", ios::app); // Abrir archivo 
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    logFile << "[" << nivelSeveridad << "] " << mensaje << endl;
    logFile.close();
}

// Errores con archivo y línea
void logMessage(const string& mensaje, const string& archivo, int linea) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    logFile << "[ERROR] " << mensaje << " (Archivo: " << archivo << ", Línea: " << linea << ")" << endl;
    logFile.close();
}

// Accesos de usuario
void logMessage(const string& mensaje, const string& usuario, bool esAcceso) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    logFile << "[SECURITY] Usuario: " << usuario << " - " << mensaje << endl;
    logFile.close();
}

int main() {
    // Pruebas
    logMessage("Este es un mensaje de depuración", "DEBUG");
    logMessage("El sistema ha iniciado correctamente", "INFO");
    logMessage("Posible problema detectado", "WARNING");
    logMessage("Error al abrir el archivo de configuración", "ERROR");
    logMessage("Fallo crítico en el sistema", "CRITICAL");
    
    // Prueba con archivo y línea
    logMessage("Error en la función cargarDatos", "main.cpp", 42);
    
    // Prueba de seguridad
    logMessage("Access Granted", "usuario1", true);
    logMessage("Access Denied", "usuario2", true);
    
    // Simulación de error en runtime
    try {
        throw runtime_error("Error inesperado en la ejecución");
    } catch (const exception& e) {
        logMessage(e.what(), "main.cpp", __LINE__);
        return 1; // Salir con código de error
    }
    
    cout << "Mensajes escritos en log.txt" << endl;
    return 0;
}
