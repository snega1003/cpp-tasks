#include <iostream>
#include <algorithm>
#include "line_number_buffer.hh"
#include <string>
using namespace std;

void cout_buf(string str) {
	auto oldbuf = std::cout.rdbuf();
	line_number_buffer buf{ oldbuf };

	ostream line_number_put(&buf);
	cout << "Input: " << str << endl;
	cout << "Output:\n";
	line_number_put << str;
	line_number_put.flush();
} 

void cin_buff() {
	auto oldbuf = std::cout.rdbuf();
	line_number_buffer buf{ oldbuf };

	ostream line_number_put(&buf);
	char c;
	while ((c = getchar()) != EOF) {
		line_number_put << c;
		line_number_put.flush();
	}
}

int main() {

	string str = "Hello\nWorld!\nWhat a wonderful day!";
	
	cout_buf(str);
	
	cin_buff();

	system("pause");
	return 0;
}

