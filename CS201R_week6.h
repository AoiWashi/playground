#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include "Instructions.h"

bool CompareStr(string a, string b);
vector<string> SplitStrByDelim(string str, char delim);
string TrimStrByDelim(string str, char delim);
bool mymethod(string s, string* output);
string PrintBinary(int num);
bool is_num(string str);