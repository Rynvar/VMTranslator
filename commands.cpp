#include <string>
#include <iostream>
#include <sstream>

void math_command(std::string command, std::stringstream& ss){

	//result = x + y;
	if (command == "add"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//load "y" variable into D
		ss << "D = M" << std::endl;

		//Point to stack, decrement by 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//replace "x" with result "x + y"
		ss << "M = M + D" << std::endl;

		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
	}

	//result = x - y;
	else if (command == "sub"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//load "y" variable into D
		ss << "D = M" << std::endl;

		//Point to stack, decrement by 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//replace "x" with result "x - y"
		ss << "M = M - D" << std::endl;

		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
		
	}

	//result = (x & y); bitwise and
	else if (command == "and"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//load "y" variable into D
		ss << "D = M" << std::endl;

		//Point to stack, decrement by 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//replace "x" with result "x & y"
		ss << "M = M & D" << std::endl;

		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
	}

	//result = (x | y); bitwise or
	else if (command == "or"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//load "y" variable into D
		ss << "D = M" << std::endl;

		//Point to stack, decrement by 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//replace "x" with result "x | y"
		ss << "M = M | D" << std::endl;

		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
	}

	//result = -y;
	else if (command == "neg"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//negate variable "y" (decimal)
		ss << "M = -M" << std::endl;
		
		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
	}

	//result = !y
	else if (command == "not"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//negate variable "y" (bitwise)
		ss << "M = !M" << std::endl;

		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
		
	}

	

	//result = (x == y); (1 if equal, 0 if not)
	else if (command == "eq"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//load "y" variable into D
		ss << "D = M" << std::endl;

		//Point to stack, decrement by 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//compute x - y to see if they're equal
		ss << "D = M - D" << std::endl;

		//M points to "x"; M also points to where the result is to be stored; we don't need "x" anymore so we init M = 0 (False = 0; True = -1)
		ss << "M = 0" << std::endl;

		//we will use 2 labels and 2 jumps for the if/else logic; if x != y go to END, if not negate(bitwise) M to produce True
		ss << "@EQ" << std::endl;
		ss << "D;JEQ" << std::endl;
		ss << "@END" << std::endl;
		ss << "0;JMP" << std::endl;

		ss << "(EQ)" << std::endl;
		ss << "M = !M" << std::endl;
		ss << "(END)" << std::endl;
		
		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
	}

	//result = (x > y); true if x > y, else false
	else if (command == "gt"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//load "y" variable into D
		ss << "D = M" << std::endl;

		//Point to stack, decrement by 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//compute x - y to see if which is greater
		ss << "D = M - D" << std::endl;

		//M points to "x"; M also points to where the result is to be stored; we don't need "x" anymore so we init M = 0 (False = 0; True = -1)
		ss << "M = 0" << std::endl;

		//we will use 2 labels and 2 jumps for the if/else logic; if x > y, negate(bitwise) M to produce True, else go to END (M remains 0)
		ss << "@GT" << std::endl;
		ss << "D;JGT" << std::endl;
		ss << "@END" << std::endl;
		ss << "0;JMP" << std::endl;

		ss << "(GT)" << std::endl;
		ss << "M = !M" << std::endl;
		ss << "(END)" << std::endl;

		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
	}

	//result = (x < y); true if x < y, else false
	else if (command == "lt"){
		//Point to stack, decrement 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//load "y" variable into D
		ss << "D = M" << std::endl;

		//Point to stack, decrement by 1, and load stack address into A
		ss << "@SP" << std::endl;
		ss << "AM = M - 1" << std::endl;

		//compute x - y to see if which is greater
		ss << "D = M - D" << std::endl;

		//M points to "x"; M also points to where the result is to be stored; we don't need "x" anymore so we init M = 0 (False = 0; True = -1)
		ss << "M = 0" << std::endl;

		//we will use 2 labels and 2 jumps for the if/else logic; if x < y, negate(bitwise) M to produce True, else go to END (M remains 0)
		ss << "@LT" << std::endl;
		ss << "D;JLT" << std::endl;
		ss << "@END" << std::endl;
		ss << "0;JMP" << std::endl;

		ss << "(LT)" << std::endl;
		ss << "M = !M" << std::endl;
		ss << "(END)" << std::endl;

		//return stack pointer to top of stack
		ss << "@SP" << std::endl;
		ss << "M = M + 1" << std::endl;
	}
	else {
		ss << "Error arithmetic command" << std::endl;
	}
}
//ss << "" << std::endl;


void mem_access_command(std::string command, std::string arg1, std::string arg2, std::stringstream& ss){

	//push command
	if (command == "push"){

		if (arg1 == "constant"){
			ss << "@" + arg2 << std::endl;
			ss << "D = A" << std::endl;
			ss << "@SP" << std::endl;
			ss << "M = " << std::endl;
			ss << "" << std::endl;
			ss << "" << std::endl;
		}
	}

	//pop command
	if (command == "pop"){

	}

}



void prog_flow_command(std::string command, std::string arg1, std::stringstream& ss){




}



void func_calling_command(std::string command, std::string arg1, std::string arg2, std::stringstream& ss){





}