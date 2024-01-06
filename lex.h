/*
 * lex.cpp by sharll-large
 * parse pok codes
*/

#ifndef LEX_CPP
#define LEX_CPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "builtin/functions/basic/exception.h"

using namespace std;

vector<char> alone = {'{', '}', '<', '>', '(', ')', '[', ']', ',', ';', '~', ':', '?', '-', '+', '*', '/', '%', '.', '^', '&', '!'};
vector<char> quote_like = {'\'', '\"'};
vector<char> space_like = {' ', '\t', '\n'};
char ignore_char = '#';

template<typename T>
bool find(vector<T> &set, T target) {
	return any_of(set.begin(), set.end(), [&](T t){return t == target;});
}

void push_if_not_null(vector<string> &target, const string& o) {
	if(!o.empty()) target.emplace_back(o);
}

vector<string> parse(vector<string> codes, char filename[]){
	vector<string> result;
	string current;
	char in_quote = 0;

	for(int x=0; x<codes.size(); x++){
		string source = codes[x];
		for(char i: source) {
			if(!in_quote){
				if(i == ignore_char) {
					break;
				} else if (find(space_like, i)) {
					push_if_not_null(result, current);
					current = "";
				}
				else
				{
					if (find(alone, i))
					{
						push_if_not_null(result, current);
						current = "";
						result.emplace_back(1, i);
					}
					else
					{
						current += i;
						if(find(quote_like, i)){
							in_quote = i;
						}
					}
				}
			}else{
				if(i == in_quote) {
					push_if_not_null(result, current + i);
					current = "";
					in_quote = 0;
				} else {
					current += i;
				}
			}
		}
		if(in_quote) {
			pok_exception(filename, x+1, "quote never closed.");
			return {};
		}
	}
	return result;
}

vector<string> readfile(char *filename) {
	vector<string> result;
	ifstream fin;
	fin.open(filename,ios::in);

	if(!fin.is_open()) {
		pok_exception(filename, 0, "Cannot open file!");
	}

	string line;
	while(getline(fin, line)) {
		result.emplace_back(line);
	}
	fin.close();

	return result;
}

vector<string> parse(char filename[]) {
	return parse(readfile(filename), filename);
}

#endif