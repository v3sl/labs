#include <iostream>

void task1(){
    int numerator = -2000;
    unsigned int denomerator = 1000;
    _asm {
        mov eax, numerator      ; eax <- numerator
    getAbs:
        neg eax                 ; abs(numerator)
        js getAbs
        mov ebx, denomerator    ; ebx <- denomerator
    beg:            
        cmp eax, ebx       
        je end
            jg gr           
            sub ebx, eax            ; gcd(eax, ebx)
            jmp beg
        gr:
            sub eax, ebx
            jmp beg
    end:                       ; gcd in eax and ebx
        mov eax, numerator      ; eax <- numerator
        mov ecx, 1              ; eax <- 1
        imul ecx                ; eax *= ecx 
        idiv ebx                ; eax /= ebx
        mov numerator, eax      ; numerator <- eax
        mov eax, denomerator    ; eax <- denomerator
        mul ecx                 ; eax*= ecx 
        div ebx                 ; eax /= ebx 
        mov denomerator, eax    ; denomerator <- eax
    }
    std::cout << numerator << std::endl << denomerator << std::endl;
}
void task2(){
    unsigned int a = 14; 
    int result;
    _asm{
        mov eax, a              ; eax <- a
        mov ebx, 0              ; ebx <- b
    beg:
        cmp eax, 0              ; while eax != 0 
        je end                    
            jg gr
                jmp end
            gr:
                mov ecx, 1      ; ecx <- 1
                mul ecx         ; eax *= ecx 
                mov ecx, 2      ; ecx <- 2
                div ecx         ; eax /= 2
                inc ebx         ; ++ebx
        jmp beg
    end: 
        mov result, ebx         ;result <- ebx
    }
    std::cout << result << std::endl;
}

void task3(){
    int a[] = {1,2,3,4,5,6,7};
    int left = -1;
    int right = 7;
    int result;
    int b = 5;
    while (right - left > 1){
        int middle = (right + left) / 2;
        if (a[middle] >= b)
            right = middle;
        else
            left = middle;
    }
    if (a[right] == b)
        result = right + 1;
    std::cout << "c++ code " << result << std::endl;
    left = -1;
    right = 7;
    result = 0;
    _asm{
        mov ebx, right                  ;ebx <- right
        sub ebx, left                   ;ebx -= left
    beg1: 
        cmp ebx, 1                      ; while ebx > 1
        jle end1
            mov eax, left               ; eax <- left  
            add eax, right              ; eax += right
            mov ecx, 1                  ; ecx <- 1
            mul ecx                     ; eax *= 1
            inc ecx                     ; ++ecx 
            div ecx                     ; eax /= ecx 
            mov ecx, b                  ; ecx <- b
            cmp ecx, a[eax*4]           ;if b < a[middle]
            jnle end2 
                    mov right, eax      ; rigth <- eax
                    jmp end3
            end2:                       ;else
                mov left, eax           ; left <- eax
            end3:
                mov ebx, right          ; ebx <- right
                sub ebx, left           ; ebx -= left 
                jmp beg1            
    end1:  
        cmp ecx, a[eax*4]               ; if ecx == a[right]
        jne end4                    
            mov ebx, right              ; ebx <- right
            mov result, ebx             ; result <- ebx 
            inc result                  ; ++result
            jmp end5                
        end4:                           ;else
            mov result, 1               ; result <- 1
            neg result                  ; result *= -1
        end5:
    }
    std::cout << "asm code " << result << std::endl;

}
void task4(){
    int a[] = {1,2,3,3,7,7,7,8,9,10};
    int first = 0; 
    int defaultLength = 1;
    int newLength = 0;
    int i = 0;
    while(i < 10){
        newLength = 0;
        if (a[i] == a[i + 1]){
            first = i+1;
            int j = i;
            while (a[j] == a[i]){
                ++newLength;
                ++j;
            }
            i = j-1;
            if (newLength > defaultLength )
                defaultLength = newLength;
        }
        ++i;
    }
    std::cout << "c++ code " <<"first " << first << " length " << defaultLength << std::endl;
    first = 0; 
    defaultLength = 1;
    newLength = 0;
    _asm{
        mov ecx, 0                  ; ecx <- 0
    beg1:
        cmp ecx, 10                 ; while ecx < 10
        jge end1       
            mov newLength, 0        ; newLength <- 0
            mov eax, a[ecx*4]       ; eax <- a[i]
            mov ebx, a[ecx*4 + 4]   ; ebx <- a[i+1]
            cmp eax, ebx            ; if eax == ebx 
            jne jne1                
                mov first, ecx      ; first <- ecx
                inc first
                mov ebx, ecx        ; ebx <- ecx 
        beg2:
            mov eax, a[ebx*4]       ; eax <- a[j]
            cmp eax, a[ecx*4]       ; while a[j] == a[i]
            jne end2            
                inc newLength       ; ++newLength
                inc ebx             ; ++ebx
                jmp beg2   
        end2:
            mov ecx, ebx            ; ecx <- ebx
            dec ecx                 ; --ecx
            mov ebx, newLength      ; ebx <- newLength
            cmp ebx, defaultLength  ; if length > defaultLength
                    jle jle1    
                    mov defaultLength, ebx    ; defaultLength <- ebx
                    jle1:       
        jne1:           
            inc ecx                 ; ++ecx            
            jmp beg1
        end1:
    }
    std::cout <<"asm code " << "first " << first << " length " << defaultLength << std::endl;
}
void task5(){
    int a[] = {1,1,1,2,3,4,4,5,6};
    int newA[6];
    int flag = 1;
    int b = 0;
    int i = 0;
    while(i < 9){
        flag = 1;
        int j = 0;
        while (j <= b){
            if (b == 0){
                newA[b++] = a[i];
                flag = 0;
                break;
            }
            if (a[i] == newA[j]){
                flag = 0 ;
                break;
            }
            ++j;
        }
        if (flag)
            newA[b++] = a[i];
        ++i;
    }
    std::cout << "c++ code ";
    for(int i = 0 ; i < 6; ++i)
        std::cout << newA[i] << ' ';
    flag = 1;
    b = 0;
    int newB[6];
    _asm{
        mov ecx, 0                             ; ecx <- 0
        mov eax, 0                             ; eax <- 0
    beg1:
        cmp ecx, 9                           ; while ecx < size
        jge end1                               
            mov flag, 1                        ; flag <- 1
            mov ebx, 0                         ; ebx <- 0      
            beg2:
                cmp ebx, eax                   ; while ebx < b 
                jg end2                         
                    mov edx, a[ecx*4]          ; edx <- a[i]
                    cmp eax, 0                 ; if b == 0 
                    jne jne1                   
                        mov newB[eax*4], edx   ; newA[0] = edx
                        inc eax                ; ++eax
                        mov flag,0             ; flag <- 0
                        jmp end2               ; break
                    jne1:                      
                    cmp edx, newB[ebx*4]       ; if edx == newA[j]
                    jne jne2
                        mov flag,0             ; flag <- 0
                        jmp end2               ; break
                    jne2:
                        inc ebx                ; ++ebx
                        jmp beg2
            end2:
                cmp flag,1                     ; if flag == 1
                jne jne3
                    mov newB[eax*4], edx       ; newA[eax] <- edx
                inc eax                        ; ++eax
                jne3:
                    inc ecx                    ; ++ecx
                    jmp beg1
    end1:
    }
    std::cout << "asm code ";
    for(int i =0 ; i < 6; ++i)
        std::cout << newB[i] << ' ';
}

int main(){
    task5();
    return 0;
}