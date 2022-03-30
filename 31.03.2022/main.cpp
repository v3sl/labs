#include <iostream>

extern "C" void __fastcall IntToHex(int, char*);
extern "C" void __fastcall IntToOct(int, char*);
extern "C" void __fastcall IntToDec(int, char*);
extern "C" int __fastcall StrToInt32(char*);
extern "C" char* __fastcall StrChar(const char* str, char symbol);
extern "C" int __fastcall  StrCompare(char* str1, char* str2);
extern "C" char __fastcall CharByIndex( char* str, int index);
extern "C" int __fastcall Max(int**, int);



int main(){
	int numb = 11; 
	char str[9];
	IntToHex(numb, str);
	std::cout << "IntToHex = " << str << std::endl;
	char str2[11];
	IntToOct(numb, str2);
	std::cout << "IntToOct = " << str2 << std::endl;
	char str3[33];
	IntToDec(numb, str3);
	std::cout << "IntToDec = " << str3 << std::endl;
	char str4[] = "12345";
	int result = StrToInt32(str4);
	std::cout << "StrToInt32 = " << result << std::endl;
	char str5[] = "hello";
	char symbol = 'l';
	char* ptr = StrChar(str5, symbol);
	std::cout << "StrChar = " << (void *)ptr << std::endl;
	char str6[] = "333";
	char str7[] = "343";
	int cmp = StrCompare(str6, str7);
	std::cout << "StrCompare = " << cmp << std::endl;
	std::cout << strcmp(str6, str7) << std::endl;


	char str8[] = "abcde";
	int index = 6;
	char a = CharByIndex(str8, index);
	std::cout << "CharByIndex = " << a << std::endl;
	int n = 5;
	int** A = new int* [n];
	for (int i = 0; i < n; ++i){
		A[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			A[i][j] = rand() % 100;
			std::cout << A[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << "Max = " << Max(A, 5) << '\n';
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
	return 0;
}
