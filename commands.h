#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include <sstream>

//Translates the passed VM command into corresponding .hack instructions
void math_command(std::string command, std::stringstream& ss);

void mem_access_command(std::string command, std::string arg1, std::string arg2, std::stringstream& ss);

void prog_flow_command(std::string command, std::string arg1, std::stringstream& ss);

void func_calling_command(std::string command, std::string arg1, std::string arg2, std::stringstream& ss);

#endif