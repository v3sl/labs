#include <iostream>

void task4(){
    int* array =  new int[] {1,1,1,2,3,4,4,4};
    int* newAarray = new int[5];
    int i = 0;
    int newArraySize = 0; 
    while (i < 8){
        int checkElement = 1;
        if(newArraySize == 0){
            checkElement = 0;
            newAarray[newArraySize+1] = array[i];
            ++i;
            ++newArraySize;
            continue;
        }
        int j = 0;
        while(j < i){
            if(array[j] == array[i] ){
                checkElement = 0;
                break;
            }
            ++j;
        }
        if(checkElement){
            newAarray[newArraySize+1] = array[i];
            ++newArraySize;
        }
        ++i;
    }
    newAarray[0] = newArraySize;
    array = newAarray; 
    std::cout << "new array " << std::endl;
    for(int i = 0; i < 5 ; i++)
        std::cout << array[i] << ' ';
    std::cout <<std::endl << "new size " << newArraySize << std::endl;
}
void task5(){
    int firstArray[] = {1,3,5,12};
    int secondArray[] = {1,2,3,4,6,8,10};
    int result[11];
    int i = 0;
    int firstArrayCounter = 0;
    int secondArrayCounter = 0;
    int resultCounter = 0; 
    while(i < 11){
        if(firstArray[firstArrayCounter] < secondArray[secondArrayCounter] && 
            firstArrayCounter != 4 ||
            secondArrayCounter == 7){
            result[resultCounter++] = firstArray[firstArrayCounter];
            ++firstArrayCounter;
            ++i;
            continue;
        }
        else{
                result[resultCounter++] = secondArray[secondArrayCounter];
                ++secondArrayCounter;
                ++i;
                continue;
        }
        ++i;
    }
    std::cout << "new arary" << std::endl;
    for(int i = 0 ; i < 11; ++i)
        std::cout << result[i] << ' ';
}
void asmTask1(){
    const char* firstWord = "233";
    const char* secondWord = "123";
    int firstWordSize = strlen(firstWord);
    int secondWordSize = strlen(secondWord);
    int minSize = std::min(firstWordSize, secondWordSize);
    int i = 0;
    int result = 0;
    std::cout << "strcmp " << strcmp(firstWord, secondWord) << std::endl;
    while(i < minSize){
        if (firstWord[i] > secondWord[i]){
            result = 1;
            break;
        }
        if (firstWord[i] < secondWord[i]){
            result = -1;
            break;
        }
        ++i;
    }
    if(result == 0){
        if(firstWordSize > secondWordSize)
            result = 1;
        if(firstWordSize < secondWordSize)
            result = -1;
    }
    std::cout << "c++ code " << result << std::endl;
    result = 0;
    _asm{
        mov ecx, 0 
        mov edx, firstWord
        mov ebx, secondWord
    beg:
        cmp ecx, minSize
        je end 
            mov eax, [ebx][ecx]
            cmp [edx][ecx], eax
            jle jle1 
                mov eax, 1
                mov result, eax
                jmp end 
        jle1:
            mov eax, [ebx][ecx]
            cmp [edx][ecx], eax
            jg jge1
                mov eax, -1
                mov result, eax
                jmp end 
        jge1:
            inc ecx 
            jmp beg
    end: 
        mov eax, 0 
        cmp result, eax 
        jne jne1 
            mov eax, firstWordSize
            mov ebx, secondWordSize
            cmp eax, ebx 
                jle jle2
                    mov ecx, 1
                    mov result, ecx 
                    jmp jne1
            jle2:
                cmp eax, ebx 
                jge jge2 
                    mov ecx, -1 
                    mov result, ecx 
                    jmp jne1 
            jge2:
                jmp jne1
    jne1:
    }
    std::cout << "asm code " << result << std::endl; 
}
void asmTask2(){
    const int matrixSize = 5;
    int matrix[matrixSize][matrixSize]{
            {5,2,3,4,5},
            {1,2,3,4,5},
            {1,2,2,4,5},
            {1,2,3,2,5},
            {1,2,3,4,2}
    };
    int result = 0;
    int i = 0;
    while (i < matrixSize){
        result+=matrix[i][i];
        result+= matrix[4-i][i++];
    }
    result -= matrix[2][2];
    std::cout << "c++ code " << result << std::endl; 
    result = 0;
    _asm{
        mov ecx,0
    begin:
        cmp ecx, matrixSize
        je end
            mov eax, matrixSize
            mul ecx
            add eax, ecx
            mov esi, eax 
            mov edi, matrix[esi*4] 
            add result, edi
            mov eax, matrixSize 
            mov ebx, 4
            sub ebx, ecx 
            mul ebx  
            add eax ,ecx 
            mov esi, eax 
            mov edi, matrix[eax*4]
            add result, edi
            inc ecx
            jmp begin  
    end:
        mov eax, matrixSize 
        mov ecx, 3 
        mul ecx 
        add eax, ecx 
        mov esi, eax 
        mov edi, matrix[eax*4]
        sub result, edi
    }
    std::cout << "asm code "<< result << std::endl;
}
void asmTask3(){
    int matrixSize = 3; 
    int**matrix = new int*[matrixSize]; 
    matrix[0] = new int[matrixSize] {6,2,3};
    matrix[1] = new int[matrixSize] {4,11,6};
    matrix[2] = new int[matrixSize] {7,8,9};
    int result = 0;
    int i = 0;
    while (i < matrixSize){
        result+=matrix[i][i];
        result+= matrix[2-i][i++];
    }
    result -= matrix[1][1];
    std::cout << "c++ code " << result << std::endl;
    result = 0;
    _asm{
        mov edx, matrix
        mov ecx, 0 
    beg:
        cmp ecx, matrixSize 
        je end
            mov eax, [edx][ecx*4]
            mov ebx, [eax][ecx*4]
            add result, ebx
            mov ebx, 2
            sub ebx, ecx 
            mov eax, [edx][ebx*4]
            mov ebx, [eax][ecx*4]
            add result, ebx 
            inc ecx
            jmp beg
    end:      
        mov ecx, 1 
        mov eax, [edx][ecx*4]
        mov ebx, [eax][ecx*4]
        sub result, ebx
    }
    std::cout << "asm code " << result << std::endl;
}

int main(){ 
    asmTask3();
    return  0;
}