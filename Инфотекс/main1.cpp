#include <iostream>
#include <locale>
#include <string>
#include <stdlib.h>
#include <cstddef>
#include <thread>


using namespace std;

string change_string(string s){
	string new_s = "";
	
	for (int i = 0; i < s.length(); i++){
		if (s[i] % 2 == 0){
			new_s += "KB";
		}
		else{
			new_s += s[i];
		}
	}
	return new_s;
}

bool check_string(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] - '0' < 0 || s[i] - '0' > 9) return false;
	}
	return true;
}

string sort(string s){
	for(int i = 0; i < s.length(); i++){
		for(int j = 0; j < s.length() - i - 1; j++){
			if(s[j] < s[j+1]){
				int temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
	return s;
}

string func1(){
	string s;
	cin >> s;
	if (s.length() > 64){
		cout << "Message length is more than 64 characters!" << endl;
		system("pause");
		system("cls");
	}
	else if (!check_string(s)){
		cout << "The string must contain only numbers!" << endl;
		system("pause");
		system("cls");		
	}
	else{
		s = sort(s);
		cout << change_string(s) << endl;
		system("pause");
		system("cls");
		return s;
	}
		
}


void func2(string s){
	int sum = 0;
	cout << s << endl;
	for(int i = 0; i < s.length(); i++){
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
			sum += s[i] - '0';
		}
	}
	
	
}

int main(){
	setlocale(0, "");
	while(true){
		string s = func1();
		func2(s);
	}
	return 0;
}
