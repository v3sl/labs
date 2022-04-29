#include <iostream> 

void function(int B[][100], int capacity, int size){
    int result;
    _asm{
        mov eax, type B
        mov result, eax 
    }
    std::cout << result;
}


// int main(){
//     const int capacity = 100;
//     int A[capacity][capacity];
//     int size = 5;
//     //! init a 
//     //function(A, capacity, size);

//     int numb = -2;
//     char str2[33];
//     str2[32] = 0; 
//     char str3[9];
//     str3[8] = '\0';
//     char abc[] = "0123456789ACBDEF";
//     char abcd[] = "012345678";
    // char str4[16];
    // str4[15] = '\0';
    // _asm{
    //     mov ecx, 32
    //     mov eax, numb
    //     beg: 
    //         shr eax, 1 
    //         jc one 
    //         mov str2[ecx-1], '0'
    //         jmp cont
//         one:
//             mov str2[ecx-1], '1'
//         cont:
//         loop beg
//     }
    // _asm{
    //     mov ecx, 8
    //     mov eax, numb
    //     beg1: 
    //         mov ebx, eax
    //         and ebx, 0x00000000F
    //         mov dl,  abc[ebx]
    //         mov   str3[ecx-1], dl
    //         shr eax, 4
    //     loop beg1
    // }
    // _asm{
    //     mov ecx, 10
    //     mov eax, numb
    //     beg3: 
    //         mov ebx, eax
    //         and ebx, 0x00000007
    //         mov dl,  abcd[ebx]
    //         mov   str4[ecx-1], dl
    //         shr eax, 3
    //     loop beg3
    // }

    // char strNumber[] = "12345";
    // int intNumer;
    // _asm{
        //     xor ebx, ebx 
        //     xor esi, esi 
        //     xor edx, edx
    // beg4: 
    //     mov dl, strNumber[esi]
    //     cmp dl, 0
    //     je end4 
    //         mov al, dl 
    //         imul ebx, 10
    //         sub dl , '0'
    //         add ebx, edx
    //         inc esi
    //         jmp beg4
    // end4:
    //     mov intNumer, ebx
    // }
//     std::cout << intNumer << std::endl;
    
//     return 0;
// }

#include <iostream>
#include "test.asm"
extern "C" int _fastcall Remainder(int,int);
void main()
{
    std::cout <<"remainder="<<Remainder(-12,5) << std::endl;
} 