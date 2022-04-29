.386

.model flat

public @CreateVectorB@16

public @IsMin@8
public @IsMax@8
public @FindSaddlePoints@8

.data

  n dd ?
  m dd ?
  rowOffset dd ?

  rows dd ?
  columns dd ?
  min dd ?
  point dd ?

.code

    @CreateVectorB@16 proc

        mov n, edx             
        mov ebx, ecx           
        mov eax, [esp + 4]
        mov m, eax             
        mov esi, [esp + 8]          
        mov eax, m             
        mov ecx, 4            
        mul ecx
        mov rowOffset, eax
        mov ecx, m
    beg1:
        cmp ecx, 0
        je end1
        xor eax, eax        
        push ecx
        push ebx
        push esi
        mov ecx, n
    beg2:
        cmp ecx, 0
        je end2
        xor esi, esi
        cmp [ebx], esi        
        jne ifNotEqual
        inc eax        
    ifNotEqual:
        add ebx, rowOffset   
        dec ecx
        jmp beg2
        end2:
        pop esi
        pop ebx
        pop ecx
        mov [esi], eax        
        add esi, 4            
        add ebx, 4  
        dec ecx
        jmp beg1
    end1:
        mov [esp + 8], esi  
        ret
    @CreateVectorB@16 endp
    
    @IsMin@8 proc
        pop eax
        mov esi 


        

    ret

    @IsMin@8 endp

    @IsMax@8 proc

    ret

    @IsMax@8 endp

    @FindSaddlePoints@8 proc
        
     ret
    @FindSaddlePoints@8 endp
  
end