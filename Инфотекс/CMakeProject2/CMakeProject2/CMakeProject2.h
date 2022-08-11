#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void clean_buff(vector<char> buff) {
	for (int i = 0; i < buff.size(); i++) {
		if (buff[i] != '\0') {
			buff[i] = '\0';
		}
		else break;
	}
}

int check_buff(vector<char> buff) {
	int len = 0;
	int num = 0;

	for (int i = 0; i < buff.size(); i++) {
		if (buff[i] != '\0') {
			len++;
			num = num * 10 + (buff[i] - '0');
		}
		else break;
	}
	cout << " " << num << " ";
	if (len <= 2) {
		return 2;
	}
	else if (num % 32 != 0) {
		return 1;
	}
	else return 0;
}