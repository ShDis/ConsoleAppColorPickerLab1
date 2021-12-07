//v1.1.20.5.31
//v<Global.Compatibility.Year.Month.Date>

#pragma once

#include <iostream>
#include <string>
#include "Palette.h"

using namespace std;

class Terminal
{
public:
	Terminal();
	~Terminal();
	void print_help();
	bool command_input();
private:
	int symbol_test();
	void execute(int id);
	string get_arg(int num);
	string typetest(string arg);
	bool argtest();

	int argnum;
	string command;
	string arg;
	int command_id;

	const int clength = 6; //command_count
	const string commands[6] = { "?","p", "all"}; //commands
	const string commands_argtypes[6][3] = { {},{"int"},{ },{"int"} }; //argtypes [command_count][args_count+1]
	const string available_commands = "Available commands:\n->?\n->p <id> - shows palette with entered id\n->all - shows all palettes\n->p_create <number_of_elements> - creates palette\n->p <id> ";
};