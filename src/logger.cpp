#include "../include/logger.h"

Logger::Logger(){
    logSplitter();
}

Logger::~Logger(){

}

void Logger::logSplitter(){
    std::ofstream outfile("LogFile.txt", std::ios::app);
    if (outfile.is_open()){
        outfile << "=====================================================\n"<< std::endl;
        outfile.close();
    }
}

void Logger::logToFile(std::string level, std::string log){
    time_t ts;
    time(&ts);
    std::ofstream outfile("LogFile.txt", std::ios::app);

    if (outfile.is_open()){
        outfile << ctime(&ts) << " " << level << ": " << log << "\n"<< std::endl;
        outfile.close();
        std::cout << ctime(&ts) << " " << level << ": " << log << std::endl;
    }
    else{
        std::cout << "Error opening log file" << std::endl;
    }
}

std::string Logger::logLevel(enum Logger::Level level){
    std::string result;
    switch (level){
        case Logger::Info:
            result = "INFO";
            break;
        case Logger::Warning:
            result = "WARNING";
            break;
        case Logger::Error:
            result = "ERROR";
            break;
        default:
            break;
    }

    return result;
}

