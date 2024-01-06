//#include "lex.h"
//int main(int argc, char *argv[]){
//	if(argc < 2) pok_exception("N", 0, "Please input file path");
//
//	for(const string& i: parse(argv[1])) cout << i << endl;
//}
#include "lex.h"
#include "iostream"
#include "builtin/types/Integer.h"

using namespace std;

int main() {
//	Integer i;
//	i.val ++;
//	cout << i.toString();
	vector<string>c = parse("../a.pok");
	for(string i: c) {
		cout << i << ' ';
		if(i == "function") {

		}
	}
}