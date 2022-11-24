//
// Created by longyaowei on 7/27/20.
//

#ifndef ECU_LINUXTRANS_READCONFIG_H
#define ECU_LINUXTRANS_READCONFIG_H

#include <string>
#include <map>
#include <fstream>

class ReadConfig{
public:
    ReadConfig();
    ~ReadConfig();
    bool ReadConfigInformation(const std::string & filename);
    std::string ReadString(const char* section, const char* item, const char* default_value);
    int ReadInt(const char* section, const char* item, const int& default_value);
    float ReadFloat(const char* section, const char* item, const float& default_value);
private:
    bool IsSpace(char c);
    bool IsCommentChar(char c);
    void Trim(std::string & str);
    bool AnalyseLine(const std::string & line, std::string& section, std::string & key, std::string & value);

private:
    std::map<std::string, std::map<std::string, std::string> >settings_;
};

#endif //ECU_LINUXTRANS_READCONFIG_H
