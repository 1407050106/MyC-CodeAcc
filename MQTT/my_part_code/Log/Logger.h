//
// Created by longyaowei on 7/21/20.
//

#ifndef ECU_LINUXTRANS_LOGGER_H
#define ECU_LINUXTRANS_LOGGER_H

#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>

using namespace log4cpp;

class Logger{
private:
    log4cpp::PatternLayout* layout;
    log4cpp::Appender* appender;
    log4cpp::Category* logCat;
public:
    Logger(const std::string& logName,const std::string& logFilePath);
    void warn(const std::string& message);
    void error(const std::string& message);
    void info(const std::string& message);
    void destoryLog();
};

extern Logger logger;

#define  LogINFO(message) logger.info(message);
#define  LogERROR(message) logger.error(message);

#endif //ECU_LINUXTRANS_LOGGER_H
