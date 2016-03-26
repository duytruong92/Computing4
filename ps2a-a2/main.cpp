#include <iostream>
#include <string>
#include "lfsr_class.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
	string s_bit;
	LFSR *lfsr = new LFSR("010101010101010", 8);
	for (int i = 0; i < 10; i++) {
		int bit = lfsr->generate(5);
		s_bit = to_string(bit);
		cout << *lfsr << " " <<  s_bit << endl;
	}
	return 0;
}
