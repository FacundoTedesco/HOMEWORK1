#ifndef LOG_H
#define LOG_H

#include <string>

void logMessage(const std::string& mensaje, const std::string& nivelSeveridad);
void logMessage(const std::string& mensaje, const std::string& archivo, int linea);
void logMessage(const std::string& mensaje, const std::string& usuario, bool esAcceso);

#endif // LOG_H
