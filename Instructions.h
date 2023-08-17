#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

// opcode rd rs1 rs2 shiamo func
class MIPS_SU_Instruction
{
public:
	virtual string* GetBytes() {
		return new string[1]{ "not implemented" };
	};
};

class Instruction_R_type :
	public MIPS_SU_Instruction
{
public:
	Instruction_R_type(string name, string rd, string rs1, string rs2, string shiamo, string func) {

		this->name = name;
		this->rd = rd;
		this->rs1 = rs1;
		this->rs2 = rs2;
		this->shiamo = "00000";
		this->func = func;
	}
	string name;
	string rd;
	string rs1;
	string rs2;
	string shiamo;
	string func;
	string* GetBytes() {
		string* str = new string[4]{
			"00000000",
			"00000000",
			"00000000",
			"00000000"
		};
		return str;
	}
};

class Instruction_S_type :
	public MIPS_SU_Instruction
{
public:
	Instruction_S_type(string name, string rd, string rs1, string shiamo) {
		this->rs2 = "00000";
		this->func = "000000";
		this->name = name;
		this->rd = rd;
		this->rs1 = rs1;
		this->shiamo = shiamo;
	}
	string name;
	string rd;
	string rs1;
	string rs2;
	string shiamo;
	string func;
	string* GetBytes() {
		string* str = new string[4]{
			"11111111",
			"11111111",
			"11111111",
			"11111111"
		};
		return str;
	}
};

//opcode rd rs1 imm
class Instruction_I_type :
	public MIPS_SU_Instruction
{
	string* GetBytes() {
		string* str = new string[4]{
			"22222222",
			"22222222",
			"22222222",
			"22222222"
		};
		return str;
	}
};


class Instruction_Set {
public:
	Instruction_Set() {
		vector<MIPS_SU_Instruction> instructions();
	};
	/// <summary>
/// Reference type argument. The input object won't be copied.
/// if your input is a pointer type then you should sent adress of the pointer by *p sytax, or send an ordinary variable.
/// </summary>
/// <param name="instruction"></param>
	void AddInstruction(MIPS_SU_Instruction* instruction) {
		instructions.push_back(instruction);
	};
	size_t Count() {
		return this->instructions.size();
	};
	MIPS_SU_Instruction* GetInstruction(int i) {
		return instructions[i];
	};
private:
	vector<MIPS_SU_Instruction*> instructions;
};