#include <iostream>

void task1(){
    int numerator = 1;
    unsigned int denomerator = 15;
    _asm {
        mov eax, numerator
    getAbs:
        neg eax
        js getAbs
        mov ebx, denomerator
    beg:
    cmp eax, ebx
    je end_ 
        jg gr 
        sub ebx, eax
        jmp beg
        gr:
        sub eax, ebx
        jmp beg
    end_:
        mov eax, numerator 
        mov ecx, 1 
        imul ecx 
        idiv ebx 
        mov numerator, eax
        mov eax, denomerator
        mul ecx 
        div ebx
        mov denomerator, eax
    }
    std::cout << numerator << std::endl << denomerator << std::endl;
}
void task2(){
    unsigned int a = 15; 
    int result;
    _asm{
        mov eax, a 
        mov ebx, 0
    beg:
        cmp eax, 0
        je end_ 
            jg gr
                jmp end_
            gr:
                mov ecx, 1 
                mul ecx 
                mov ecx, 2 
                div ecx
                inc ebx
        jmp beg
    end_: 
        mov result, ebx
    }
    std::cout << result << std::endl;
}

void task3(){
    int a[] = {1,2,3,4,5,6,7};
    int left = -1;
    int right = 7;
    int result;
    int b = 8;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if(a[middle] >= b)
            right = middle; 
        else 
            left = middle;
    }
    if(a[right] == b)
        std::cout << right+1 << std::endl;
    else 
        std::cout << -1 << std::endl;
    left = -1;
    right = 7;
    _asm{
    mov ebx, right 
    sub ebx, left 
    begWhile: 
            cmp ebx, 1
            jle endWhile 
                mov eax, left 
                add eax, right 
                mov ecx, 1 
                mul ecx 
                inc ecx 
                div ecx 
                mov ecx, b 
                cmp ecx, a[eax*4] 
                jnle endIf 
                    mov right, eax
                    jmp endIfElse
                endIf:
                    mov left, eax
                endIfElse:
                mov ebx, right 
                sub ebx, left 
                jmp begWhile
    endWhile:  
        cmp ecx, a[eax*4]
        jne endIfElse2
            mov ebx, right
            mov result, ebx
            inc result
            jmp endProgramm
        endIfElse2: 
            mov result, 1
            neg result
        endProgramm:
    }
    std::cout << result << std::endl;

}
void task4(){

}
void task5(){
    int a[] = {1,1,1,2,2,3,4,5,6,6};
    int newA[6];
    int b = 0; 
    for(int i = 0; i < 10 ; ++i ){
        bool flag = true;
        for(int j = 0;  j <= b; ++j){
            if(b == 0){
                newA[b++] = a[i];
                flag = false;
                break;
            }
            else if (a[i] == newA[j]){
                flag = false; 
                break;
            }
        }
        if(flag)
            newA[b++] = a[i];
    }
    for(int i =0 ; i < 6; ++i){
        std::cout << newA[i];
    }
}

int main(){
    task3();
    return 0;
}