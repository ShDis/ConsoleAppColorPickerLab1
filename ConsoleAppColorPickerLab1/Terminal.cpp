//v1.1.20.5.31
//v<Global.Compatibility.Year.Month.Date>

#pragma once

#include "Terminal.h"

Terminal::Terminal()
{
	command = "";
	arg = "";
}

Terminal::~Terminal()
{

}


void Terminal::print_help()
{
	cout << available_commands << endl;
}

bool Terminal::command_input()
{
	cout << "->";
	getline(cin, command);
	//execute(symbol_test()); //old
	command_id = symbol_test();
	if (command_id == -1)
	{
		cout << "Error: command not found!" << endl;
	}
	else
	{
		if (argtest() == true)
		{
			execute(command_id);
		}
		else
		{
			string temp_args_for_error;
			if (!commands_argtypes[command_id][0].empty())
			{
				for (int i = 0; i < size(commands_argtypes[command_id]); i++)
				{
					if (commands_argtypes[command_id][i].empty())
					{
						break;
					}
					else
					{
						if (i != 0)
						{
							temp_args_for_error = temp_args_for_error + " <" + commands_argtypes[command_id][i] + ">";
						}
						else
						{
							temp_args_for_error = "<" + commands_argtypes[command_id][0] + ">";
						}
					}
				}
			}
			else temp_args_for_error = "<none>";
			cout << "Error: invalid arg type. " << "Required arg types: " << temp_args_for_error << endl;
		}
	}
	//ending
	command = "";
	return true;
}

int Terminal::symbol_test()
{
	for (int i = 0; i < clength; i++)
	{
		if ((command.find(commands[i]) == 0) && (commands[i] == get_arg(0)))
		{
			return i;
		}
	}
	return -1; //-1==error
}

bool Terminal::argtest()
{
	for (int i = 0; i < size(commands_argtypes[command_id]) + 1; i++)
	{
		if (commands_argtypes[command_id][i].empty())
		{
			if (get_arg(i + 1) == "")
			{
				return true;
			}
			else return false;
		}
		if (commands_argtypes[command_id][i] != typetest(get_arg(i + 1)))
		{
			return false;
		}
	}
}

string Terminal::typetest(string arg)
{
	bool t_string = false;
	bool t_int = false;
	bool t_double = false;
	int dot_counter = 0;
	//65-90:A-Z  97-122:a-z  48-57:0-9  45:-  46:.(dot) 32:_(space)
	for (int i = 0; i < size(arg); i++)
	{
		if ((int(arg[i]) >= 65 && int(arg[i]) <= 90) || (int(arg[i]) >= 97 && int(arg[i]) <= 122))
		{
			t_string = true;
			break;
		}
		if ((int(arg[i]) >= 48 && int(arg[i]) <= 57))
		{
			t_int = true;
		}
		if (int(arg[i]) == 46)
		{
			t_double = true;
			dot_counter += 1;
		}
	}
	if (t_string == true)
	{
		return "string";
	}
	else if (t_double == true)
	{
		if (dot_counter == 1) //TO DO. NOT WORKING CORRECTLY
		{
			if (arg[0] == '.')
			{
				arg = "0" + arg;
			}
			if (arg[size(arg) - 1] == '.')
			{
				arg += "0";
			}
			return "double";
		}
		else return "error";
	}
	else if (t_int == true)
	{
		return "int";
	}
	else return "error";
}

void Terminal::execute(int id)
{
	switch (id)
	{
	case 0:
		print_help();
		break;
	case 1:
		test.gen_graph(stoi(get_arg(1)), stoi(get_arg(2)));
		break;
	case 2:
		test.show_graph();
		break;
	case 3:
		test.get_graph(get_arg(1));
		break;
	case 4:
		test.depth_first_search_graph(stoi(get_arg(1)));
		break;
	case 5:
		test.get_mtgraph(get_arg(1));
		break;
	case 6:
		test.show_mtgraph();
		break;
	case 7:
		test.mttolt();
		break;
	case 8:
		test.dfs_oriented();
		break;
	case 9:
		test.dfs_oriented6();
		break;
	default:
		cout << "Error. Type '?' for help." << endl;
		break;
	}
}

string Terminal::get_arg(int num)
{
	argnum = 0;
	arg = "";
	for (int i = 0; i < size(command); i++)
	{
		if (command[i] == ' ')
		{
			argnum += 1;
		}
		if (argnum == num)
		{
			if (argnum == 0)
				arg += command[i]; //crutch for zero arg
			i += 1;
			while (i < size(command))
			{
				if (command[i] == ' ')
				{
					return arg;
				}
				arg += command[i];
				i++;
			}
			return arg;
		}
	}
	return arg;
}