//
// Created by longyaowei on 7/21/20.
//
#include "Logger.h"

Logger logger("Log", "./log/test.log");

Logger::Logger(const std::string& logName,const std::string& logFilePath){
    // 1. 初始化一个layout对象
    this->layout = new log4cpp::PatternLayout();
    this->layout->setConversionPattern("%d: %p %c %x: %m%n");
    // 2. 初始化一个appender 对象
    this->appender = new log4cpp::RollingFileAppender("FileAppender",logFilePath,10*1024,0);
    //Logger::appender = new log4cpp::RollingFileAppender
    // 3. 把layout对象附着在appender对象上
    this->appender->setLayout(Logger::layout);
    // 4. 实例化一个category对象
    log4cpp::Category& root = log4cpp::Category::getRoot();
    this->logCat = &root.getInstance(logName);
    // 5. 把appender对象附到category上
    this->logCat->setAppender(Logger::appender);
    // 6. 设置category的优先级，低于此优先级的日志不被记录
    this->logCat->setPriority(log4cpp::Priority::DEBUG);
    //DEBUG < INFO < WARN < ERROR < FATAL
}

void Logger::warn(const std::string& message) {
    this->logCat->warn(message);
}

void Logger::error(const std::string& message) {
    this->logCat->error(message);
    std::cout<<message<<std::endl;
}

void Logger::info(const std::string& message) {
    this->logCat->info(message);
    std::cout<<message<<std::endl;
}

void Logger::destoryLog() {
    //销毁日志对象
    log4cpp::Category::shutdown();
}