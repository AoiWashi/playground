#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;


class Instruction_Set {
public:
	Instruction_Set() {
		instructions = vector<MIPS_SU_Instruction>();
	}
	void AddInstruction(MIPS_SU_Instruction &instruction) {
		instructions.push_back(instruction);
	}
	void AddInstruction(MIPS_SU_Instruction instruction) {
		instructions.push_back(instruction);
	}
	size_t GetCount() {
		return this->instructions.size();
	}
	MIPS_SU_Instruction GetInstruction(int i) {
		return instructions[i];
	}
private:
	vector<MIPS_SU_Instruction> instructions;
};

// opcode rd rs1 rs2 shiamo func
class MIPS_SU_Instruction
{
public:
	string* GetBytes() {

	}
};

class Instruction_R_type :
	MIPS_SU_Instruction
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
		string* str = new string[1];
		str[0] = "I am R type";
		return str;
	}
};

class Instruction_S_type :
	MIPS_SU_Instruction
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
		string* str = new string[1];
		str[0] = "I am S type";
		return str;
	}
};

//opcode rd rs1 imm
class Instruction_I_type :
	MIPS_SU_Instruction
{
public:
	string name;
	string rd;
	string rs1;
	string imm;
};