#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include "Instructions.h"

using namespace std;


	bool CompareStr(string a, string b);
	vector<string> SplitStrByDelim(string str, char delim);
	string TrimStrByDelim(string str, char delim);
	bool mymethod(string s, string* output);
	string PrintBinary(int num);
	bool is_num(string str);

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

		Instruction_R_type* instruction_i = new Instruction_R_type("11111", "rd", "rs1", "shiamo");
		Instruction_R_type instruction_i_2 = Instruction_R_type("11111", "rd", "rs1", "shiamo");

		cout << instruction_i->GetBytes();
		cout << instruction_i_2.GetBytes();

		Instruction_Set i_set = Instruction_Set();

		i_set.AddInstruction(instruction_i);

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
				lastPos = i+1;
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
	