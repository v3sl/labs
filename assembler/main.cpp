#include <iostream>
#include <string>

int main(){
    int var1 = 34, var2 = -12, result;
    short int a = -3;
    char c = -3;
    int result2; //! c-var2
    int result1; //! result1 = a-var2
    //TODO c*a+a*var1+var1*c
    int product;
    int product2;
    int ost, chast;
    _asm{
        mov eax, var1; eax < -var1
        sub eax, var2
        mov result, eax

        mov eax, 0; a >= 0
        mov ax, a
        sub eax, var2
        mov result1, eax

        ; !!!mov eax, dword ptr a

        movsx eax, a
        sub eax, var2
        mov result1, eax

        movsx eax, c
        sub eax, var2
        mov result2, eax

        mov eax, var1
        imul  var2
        mov product, eax

        mov eax, var1
        mov ebx, 1
        mul ebx
        idiv var2
        mov ost, edx
        mov chast, eax
        mov product2, eax
    }
    std::cout << "res = " << result << std::endl;
    std::cout << "res1 = " << result1 << std::endl;
    std::cout << "res2 = " << result2 << std::endl;
    std::cout << "product = " << product << std::endl;
    std::cout << "ost = " << ost << std::endl;
    std::cout << "chast = " << chast << std::endl;
    std::cout << "product2 = " << product2 << std::endl;
    return 0;
}
