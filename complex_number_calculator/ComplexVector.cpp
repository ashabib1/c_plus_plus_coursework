#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "ComplexVector.h"

using namespace std;

ComplexVector::ComplexVector(string x) {
	z = x;
}

string operator+(ComplexVector s, ComplexVector t) {
	vector<string> first = s.getArray();
	vector<string> second = t.getArray();
	vector<double> third;
	for (int i = 0; i < first.size(); i++) {
		third.push_back(stod(first[i]) + stod(second[i]));
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 6));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 3));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 3));
			}
			else
				str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 4));
			}
			else
				str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 5));
			}
			else
				str.append((to_string(third[i])).substr(0, 6));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 6));
			}
			else
				str.append((to_string(third[i])).substr(0, 7));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

string operator-(ComplexVector s, ComplexVector t) {
	vector<string> first = s.getArray();
	vector<string> second = t.getArray();
	vector<double> third;
	for (int i = 0; i < first.size(); i++) {
		third.push_back(stod(first[i]) - stod(second[i]));
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 6));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 3));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 3));
			}
			else
				str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 4));
			}
			else
				str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 5));
			}
			else
				str.append((to_string(third[i])).substr(0, 6));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 6));
			}
			else
				str.append((to_string(third[i])).substr(0, 7));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

string operator*(ComplexVector s, ComplexVector t) {
	vector<string> first = s.getArray();
	vector<string> second = t.getArray();
	vector<double> third;
	for (int i = 0; i < first.size(); i += 2) {
		third.push_back((stod(first[i]) * stod(second[i])) - (stod(first[i + 1]) * stod(second[i + 1])));
		third.push_back((stod(first[i + 1]) * stod(second[i])) + (stod(first[i]) * stod(second[i + 1])));
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 6));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 3));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 3));
			}
			else
				str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 4));
			}
			else
				str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 5));
			}
			else
				str.append((to_string(third[i])).substr(0, 6));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 6));
			}
			else
				str.append((to_string(third[i])).substr(0, 7));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

string operator/(ComplexVector s, ComplexVector t) {
	vector<string> first = s.getArray();
	vector<string> second = t.getArray();
	vector<double> third;
	for (int i = 0; i < first.size(); i += 2) {
		double a = stod(first[i]);
		double b = stod(first[i + 1]);
		double c = stod(second[i]);
		double d = stod(second[i + 1]);
		third.push_back(round((((a * c) + (b * d)) / (c * c + d * d)) * 10) / 10);
		third.push_back(round((((b * c) - (a * d)) / (c * c + d * d)) * 10) / 10);
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 6));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])).substr(0, 3));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 3));
			}
			else
				str.append((to_string(third[i])).substr(0, 4));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 4));
			}
			else
				str.append((to_string(third[i])).substr(0, 5));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 5));
			}
			else
				str.append((to_string(third[i])).substr(0, 6));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])).substr(0, 6));
			}
			else
				str.append((to_string(third[i])).substr(0, 7));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

int ComplexVector::getLength() {
	int count = 1;
	for (int i = 0; i < z.length(); i++) {
		if (z[i] == ',')
			count++;
	}
	return count;
}

vector<string> ComplexVector::getNumbers() {
	for (int i = 1; i < strnumbers.size() - 1; i += 2)
		if (strnumbers[i - 1] == "-")
			numbers.push_back("-" + strnumbers[i]);
		else
			numbers.push_back(strnumbers[i]);
	return numbers;
}

vector<string> ComplexVector::putinarray() {
	istringstream instr(z);
	string temp[1000];
	for (int i = 0; i < z.length(); i++)
		instr >> temp[i];
	for (int i = 0; temp[i] != ""; i++)
		strnumbers.push_back(temp[i]);
	return strnumbers;
}

vector<string> ComplexVector::getArray() {
	return numbers;
}

string operator%(ComplexVector s, int z) {
	vector<string> first = s.getArray();
	vector<double> third;
	for (int i = 0; i < first.size(); i++) {
		third.push_back(stod(first[i]) * z);
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

string operator<(ComplexVector s, int z) {
	vector<string> first = s.getArray();
	vector<double> third;
	int r = z * z;
	for (int i = 0; i < first.size(); i++) {
		if (i % 2 == 1)
			third.push_back(stod(first[i]) * r);
		else
			third.push_back(stod(first[i]));
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

string operator>(ComplexVector s, ComplexVector t) {
	vector<string> first = s.getArray();
	vector<string> second = t.getArray();
	vector<double> third;
	for (int i = 0; i < first.size(); i += 2) {
		third.push_back((stod(first[i]) * stod(second[i])) - (stod(first[i + 1]) * stod(second[i + 1])));
		third.push_back((stod(first[i + 1]) * stod(second[i])) + (stod(first[i]) * stod(second[i + 1])));
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

string operator<=(ComplexVector s, ComplexVector t) {
	vector<string> first = s.getArray();
	vector<string> second = t.getArray();
	vector<double> third;
	for (int i = 0; i < first.size(); i += 2) {
		double a = stod(first[i]);
		double b = stod(first[i + 1]);
		double c = stod(second[i]);
		double d = stod(second[i + 1]);
		third.push_back(((((a * c) + (b * d)) / (c * c + d * d)) * 10) / 10);
		third.push_back(((((b * c) - (a * d)) / (c * c + d * d)) * 10) / 10);
	}
	string str = "{";
	for (int i = 0; i < third.size(); i++) {
		str.append(" ");
		if (third[i] >= 1000) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 100) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 10) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] >= 0.01) {
			if (i % 2 == 1)
				str.append("+ ");
			str.append((to_string(third[i])));
		}
		else if (third[i] > -10) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -100) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else if (third[i] > -1000) {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		else {
			if (i % 2 == 1) {
				str.append("- ");
				third[i] = third[i] * (-1);
				str.append((to_string(third[i])));
			}
			else
				str.append((to_string(third[i])));
		}
		if (i % 2 == 1 && i < third.size() - 1)
			str.append(" i,");
		else if (i % 2 == 1)
			str.append(" i");
	}
	str.append("}");
	return str;
}

void ComplexVector::recursiveOutput(int x, ComplexVector n) {
	if (tr == true) {
		tr = false;
		tx = x;
		x = 1;
		recPrint.append(z);
	}
	n.putinarray();
	n.getNumbers();
	ComplexVector g("{ 2 + 3 i}");
	ComplexVector h("{ 7 + 5 i}");
	g.putinarray();
	g.getNumbers();
	h.putinarray();
	h.getNumbers();
	string a = g % x;
	string b = (h < x);
	ComplexVector new1(a);
	ComplexVector new2(b);
	new1.putinarray();
	new1.getNumbers();
	new2.putinarray();
	new2.getNumbers();
	string c = (new1 <= new2);
	ComplexVector new3(c);
	new3.putinarray();
	new3.getNumbers();
	string d = (new3 > n);
	ComplexVector new4(d);
	recPrint.append(d);
	if (x < tx)
		return ComplexVector::recursiveOutput(x + 1, new4);
	else
		return;
}

void ComplexVector::printRecursive() {
	size_t index = 0;
	while (true) {
		index = recPrint.find("}{", index);
		if (index == string::npos)
			break;
		recPrint.replace(index, 2, ",");
		index += 1;
	}
	ofstream fin;
	fin.open("ComplexSequence.txt");
	fin << recPrint;
	fin.close();
	return;
}

