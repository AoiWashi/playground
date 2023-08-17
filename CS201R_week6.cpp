#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include "Instructions.h"
#include "CS201R_week6.h"

using namespace std;



int main() {
	//string first_str = "ali ben gelmek";
	//string second_str = "";

	//if (CompareStr(first_str, "ali ben gelmek")) {

	//	cout << "oldu";
	//}
	//cout << "olmadi" << endl;
	//string den = "_hdhd_gssgsg_llll__";
	////string s = TrimStrByDelim(den, '_');
	////cout << s + "\n";
	//vector<string> sv = SplitStrByDelim(den, '_');
	//cout << sv.size();
	//for (int i = 0; i < sv.size(); i++) {
	//	cout << sv[i] + "\n";
	//}

	//string out = "star";
	//mymethod("t", &out);
	//cout << out;

	//cout << PrintBinary(4) << endl;
	//cout << PrintBinary(16) << endl;
	//string str = "134a5";
	//if (is_num(str)) {
	//	cout << "calisiyor";
	//}
	//string inp = "10 m";
	//int num = stoi(inp);
	//cout << num;

	//int decimalNumber = 23;
	//std::bitset<5> binary(decimalNumber);
	//std::string binaryString = binary.to_string();

	//// Trim leading zeroes
	//size_t firstOne = binaryString.find('1');
	//if (firstOne != std::string::npos) {
	//	binaryString = binaryString.substr(firstOne);
	//}

	//std::cout << "Binary representation of " << decimalNumber << " with 5 bits is: " << binaryString << std::endl;

	//char a;
	//cin >> a;
	//cout << a * 1;

	cout << "working with instructions \n";

	Instruction_S_type* instruction_s   = new Instruction_S_type("11111", "rd", "rs1", "shiamo");
	Instruction_S_type* instruction_s_2 = new Instruction_S_type("11111", "rd", "rs1", "shiamo");
	Instruction_R_type* instruction_r   = new Instruction_R_type("11111", "rd", "rs1", "rs2", "shiamo", "func");
	Instruction_I_type* instruction_i   = new Instruction_I_type();

	Instruction_Set i_set = Instruction_Set();

	i_set.AddInstruction(instruction_s);
	i_set.AddInstruction(instruction_s_2);
	i_set.AddInstruction(instruction_r);
	i_set.AddInstruction(instruction_i);

	int count = (int)i_set.Count();

	cout << count << " instructions are in the set\n";
	for (size_t n = 0; n < i_set.Count(); n++) {
		string* msg = i_set.GetInstruction(n)->GetBytes();
		// we know there will be four bytes. we also may use a class instead of a string array
		for (int i = 0; i < 4;i++ ) {
			cout << msg[i] << "\n";
		}
	}

	// releasing memory
	delete instruction_s;
	delete instruction_s_2;
	delete instruction_r;
	delete instruction_i;
	instruction_s = NULL;
	instruction_s_2 = NULL;
	instruction_r = NULL;
	instruction_i = NULL;
	return 0;
}

bool is_num(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool mymethod(string s, string* addressOfOutput) {
	*addressOfOutput += s;
	return true;
}
string PrintBinary(int num) {
	bitset<32> bset = bitset<32>(num);
	string str = bset.to_string();
	return str;
}
bool CompareStr(string a, string b) {
	if (a.empty() && b.empty())return true;
	int length = a.length();
	if (length != b.length()) return false;
	for (int i = 0; i < length; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

vector<string> SplitStrByDelim(string str, char delim) {
	if (str.empty()) vector<string> res(1);
	int length = str.length();
	if (length == 0) vector<string> res(1);
	string newStr = TrimStrByDelim(str, delim);
	int delimCount = 0;
	length = newStr.length();
	for (int i = 0; i < length; i++) {
		if (str[i] == delim) delimCount++;
	}
	int lastPos = 0;
	vector<string> res(delimCount + 1);
	int segIndex = 0;
	int i = 0;
	do {
		if (newStr[i] == delim) {
			int l = i - lastPos; // -1 for excluding delim
			res[segIndex] = newStr.substr(lastPos, l);
			segIndex++;
			lastPos = i + 1;
		}
		i++;
	} while (i < length);
	int l = i - lastPos; // -1 for excluding out of range index
	res[segIndex] = newStr.substr(lastPos, l);
	return res;
}
string TrimStrByDelim(string str, char delim) {
	if (str.empty()) return str;
	int length = str.length();
	if (length == 0) return str;
	bool charFound = false;
	int firstChar = 0;
	int lastChar = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == delim) {
			if (!charFound) {
				firstChar++;
			}
		}
		else {
			//found
			if (!charFound) {
				lastChar = firstChar;
				charFound = true;
			}
			else {
				lastChar = i;
			}
		}
	}
	int l = lastChar - firstChar + 1;
	return str.substr(firstChar, l);
}

