#ifndef LOGGER_H
#define LOGGER_H

#include "globals.h"

class Logger{
    public:
        Logger();
        ~Logger();

        std::string message;
        enum Level {Info, Warning, Error};
        void logSplitter();
        void logToFile(std::string level, std::string log);
        std::string logLevel(enum Level);        
};

#endif