#include <iostream>


void task1(){
    int a = 5 ,result;
    char n = 2;
    _asm{
        mov eax, a      ; eax <— a
        mov cl, n       ; cl <— n
        shr eax, cl     ; shr >>*cl 
        JNC CF_0        ; 
        mov result, 1   ; result <— 1
        jmp end_        ; 
    CF_0 :              ; 
        mov result, 0   ; result <— 0
    end_ :              ; 
    }
    std::cout << result << std::endl;
}
void task2(){
    short int a = 15;
    char n = 3;
    int b = 0;
    short int c = 2;
    short int result;
    _asm{
        ;???
        mov result, 1
    }
    std::cout << static_cast<char>(result) << std::endl;
}
void task3(){
    short int a = 32, b = 4;
    _asm{
        mov ax, a       ; ax <— a
        mov bx, b       ; bx <— b
        mov a, bx       ; a <— bx
        mov b, ax       ; b <— ax
    }
    std::cout << a << std::endl << b << std::endl;
}
void task4(){
    int a = 3;
    int b = 4;
    int result;
    _asm{
        mov eax, b      ; eax <— b
        neg eax         ; b = -b
        mov ebx, 1      ; ebx <— 1
        imul ebx        ; eax*ebx
        idiv a          ; eax/a
        mov result, eax ; result <— eax
    }
    std::cout << result << std::endl;
}
void task5(){
    int a = 1;
    int b = 2;
    int c = 3;
    int x = 4;
    int result;
    _asm{
        mov eax, 1      ; eax <-1
        inc eax         ; eax++
        imul a          ; eax*= a
        imul c          ; eax *= c
        mov ecx, eax    ; ecx <- eax
        mov eax, b      ; eax <- b
        mov ebx, 1      ; ebx <- 1
        imul ebx        ; eax*= ebx (eax*= 1)
        idiv x          ; eax /= x
        sub ecx, eax    ; ecx -= eax
        sub ecx, 12     ; ecx -= 12
        mov eax, c      ; eax <- c
        imul x          ; eax *= x
        add eax, a      ; eax += a
        mov ebx, eax    ; ebx <- eax
        mov eax, ecx    ; eax <- ecx
        mov edx, 1      ; edx <- 1
        imul edx        ; eax *= edx (eax*=1)
        idiv ebx        ; eax /= ebx
        mov result, eax ; result <- eax
    }
    std::cout << result << std::endl;
}
void task6(){
    short int a = 3;
    int result;
    _asm{
        movsx eax, a    ; eax <- a
        mov bh, ah      ; bh <- ah
        mov ah, al      ; ah <- al
        mov al, bh      ; al <- bh
        mov result, eax ; result <- eax
    }
    std::cout << result << std::endl;
}
void task7(){
    int a = 10;
    int b = 100;
    int overflowFlag;
    _asm{
        mov eax, a              ; eax <- a
        imul b                  ; eax *= b
        jno OF_0   
        mov overflowFlag, 1     ; overflowFlag <— 1
        jmp end_ 
    OF_0 :
        mov overflowFlag, 0     ; overflowFlag <— 0
    end_ :
    }
    std::cout << overflowFlag  << std::endl;
}
void task8(){
    char a = 1;
    short int b = 2;
    int c = 4;
    int result;
    _asm{
        movsx eax, a        ; eax <- a
        cdq                 ; dword -> qword
        div b               ; eax /= b
        mov ebx, eax        ; ebx <- eax
        movsx eax, b        ; eax
        cdq                 ; dword -> qword
        div c               ; eax /= c
        add ebx, eax        ; ebx += eax
        mov eax, c          ; eax <- c
        cdq                 ; dword -> qword
        div a               ; eax /= a
        add ebx, eax        ; ebx += eax
        mov result, ebx     ; result <- ebx
    }
    std::cout << result << std::endl;
}
void task9(){
    int a = 2;
    char  n = 4;
    int  result;
    _asm{
        mov eax, a                      ; eax < -a        
        mov cl, n                       ; cl < -n
        dec cl                          ; cl--
        shl eax, cl                     ; eax <<*cl
        mov result, eax                 ;result < -eax   
    }
    std::cout << result << std::endl;
}
void task10(){
    short int a = 5;
    int result = 0;
    _asm{
        mov cx, 16      ; cx <- 16
        mov ax, a       ; ax <- a
        beg:
        shr ax,1        ; ax >> 
        jnc beg1       
        add result , 1  ;result += 1
        beg1:   
        loop beg
    }   
    std::cout << result << std::endl;
}
int main(){
    task2();
    return 0;
}