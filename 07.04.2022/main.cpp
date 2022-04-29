#include <iostream>

const int N = 4;
const int M = 5;

extern "C" void _fastcall CreateVectorB(unsigned int A[][M], int N, int M, int* B);

const int n = 3;
const int m = 4;


extern "C" int _fastcall IsMin(int matrix[][m], int m, int v);
extern "C" int _fastcall IsMax(int matrix[][m], int m, int v);
extern "C" int _stdcall FindSaddlePoints(int matrix[][m], int n, int m, int* results);


int mas[4][5];

int main(){
	
	int A[N][M] = {
		{0,0,0,0,0},
		{0,0,0,1,0},
		{0,0,0,1,2},
		{2321,0,1,1,3} 
	};

	int* B = new int[M];

	_asm {
		lea ecx, A       
		mov edx, N         
		mov eax, B
		push eax
		push M
		call CreateVectorB
		pop eax
		pop eax
	}

	for (size_t i = 0; i < M; i++)	
		std::cout << B[i] << std::endl;

	int matrix[n][m] = {
		{2,3,5,2},
		{2,4,6,2},
		{-2,7,2,0}
	};

	int* result = new int[M];
	
	//
	//_asm {
	//	mov ecx, result
	//	push ecx 
	//	push m
	//	push n
	//	lea ecx, matrix
	//	push ecx
	//	call FindSaddlePoints
	//	pop eax
	//	pop eax
	//	pop eax
	//	pop eax
	//}

	for (int i = 0; i < 4; i++)
		std::cin >> mas[i][0] >> mas[i][1] >> mas[i][2] >> mas[i][3] >> mas[i][4];
	int cCounter = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (IsMin(i, j) && IsMax(i, j))
			{
				cCounter++;
				std::cout << i << ' ' << j << std::endl;
			}
		}
	}
	if (cCounter == 0)
		std::cout << "Error... Не могу найти седлову точку\n";

	return 0;
}