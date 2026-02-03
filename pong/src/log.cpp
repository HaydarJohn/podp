#include "log.h"



Logger* Logger::instancePtr = nullptr;
std::mutex Logger::mutex;

Logger* Logger::getInstance()
{
    if (instancePtr == nullptr) {
        std::lock_guard<std::mutex> lock(mutex);
        if (instancePtr == nullptr) {
            instancePtr = new Logger();
        }
    }
    return instancePtr;
}

void Logger::setLogLevel(LogLevel logLevel)
{
    this->level = logLevel;
}

void Logger::log(LogLevel logLevel,std::string message)
{
    if(this->level >= logLevel)
    {
        std::cout<<message<<std::endl;
    }
}

Logger::Logger()
{
    setLogLevel(LogLevel::INFO);
}
Logger::~Logger()
{
    delete this->instancePtr;
}
