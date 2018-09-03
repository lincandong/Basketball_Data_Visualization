#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>

class parameters {};

class dataParameter : public parameters
{
public:
    std::string name;   // 球队名字
    std::string option; // 球队哪项数据的历史
    std::string begin;
    std::string end;
    dataParameter(std::string name, std::string option, std::string begin, std::string end) : name(name), option(option), begin(begin), end(end) {}
};  // 绑定一个vector，存储球队/球员的该项数据的历史记录

class rankParameter : public parameters
{
public:
    std::string option;  // 用来排序的选项，按照爬去的名字来看
    int season; // 赛季
    
    rankParameter(std::string option, int season): option(option), season(season) {}

};  // 绑定一个大小为15的vector，存储前15名球队/球员的该项数据


#endif // PARAMETERS_H
