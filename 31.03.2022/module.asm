.386


PUBLIC @IntToHex@8
PUBLIC @IntToOct@8
PUBLIC @IntToDec@8
PUBLIC @StrToInt32@4
PUBLIC @StrChar@8
PUBLIC @StrCompare@8
PUBLIC @CharByIndex@8

.model flat

.data
	abc db "0123456789ABCDEF"
.stack 100
.code
	@IntToHex@8 proc
		xor bl, bl
		mov [edx][8], bl
		mov eax, 8
	convertBegin:
		cmp eax, 0 
		je convertEnd
		mov ebx, ecx
		and ebx, 15
		mov bl, abc[ebx]
		mov [edx][eax-1], bl
		shr ecx, 4
		dec eax 
		jmp convertBegin
	convertEnd:
		ret
	@IntToHex@8 endp
	@IntToOct@8 proc
		mov bl, 0
		mov [edx][10], bl
		mov eax, 10
	convertBegin:
		cmp eax, 0 
		je convertEnd
		mov ebx, ecx
		and ebx, 7
		mov bl, abc[ebx]
		mov [edx][eax-1], bl
		shr ecx, 3
		dec eax 
		jmp convertBegin
	convertEnd:
		ret
	@IntToOct@8 endp
	@IntToDec@8 proc 
		mov bl, 0
		mov [edx][32], bl
		mov eax, 32
	convertBegin:
		cmp eax, 0 
		je convertEnd
		mov ebx, ecx
		and ebx, 1
		mov bl, abc[ebx]
		mov [edx][eax-1], bl
		shr ecx, 1
		dec eax 
		jmp convertBegin 
	convertEnd:
		ret
	@IntToDec@8 endp
	@StrToInt32@4 proc 
		xor ebx, ebx 
		xor esi, esi 
		xor edx, edx
	convertBegin:
		mov dl, [ecx][esi]
		cmp dl ,0 
		je convertEnd
		mov al, dl
		imul ebx, 10
		sub dl , '0'
		add ebx, edx
		inc esi
	    jmp convertBegin
	convertEnd:
		mov eax, ebx
		ret
	@StrToInt32@4 endp
	@StrChar@8 proc
		xor esi, esi
	findSymbolBegin:
		mov bl, [ecx][esi] 
		cmp bl, 0
		je findSymbolEnd 
		cmp dl, bl
		jne isNotEqual
		lea eax, [ecx+[esi]]
		ret
	isNotEqual:
		inc esi
		jmp findSymbolBegin
	findSymbolend:
		ret
	@StrChar@8 endp
	@StrCompare@8 proc 
		xor esi, esi
		xor ebx, ebx 
		xor eax, eax
	compareBegin:
		mov bl,[ecx][esi]
		cmp bl, 0
		je firstIsEqual
		mov al,[edx][esi]
		cmp al, 0
		je secondIsEqual
		cmp bl, al 
		je isEqual
		cmp bl, al
		jg isGreater
		mov eax, -1
		ret
	isGreater:
		mov eax, 1
		ret
	isEqual:
		inc esi
		jmp compareBegin
	secondIsEqual:
		mov eax, 1
		ret
	firstIsEqual:
		mov al,[edx][esi]
		cmp al, 0
		je	isEqual2
		mov eax, -1
		ret 
	isEqual2:
		mov eax, 0
		ret
	@StrCompare@8 endp
	@CharByIndex@8 proc
		mov eax, 0
		xor esi, esi 
	findBegin:
		mov bl, [ecx][esi]
		cmp bl ,0 
		je findEnd
		cmp esi, edx 
		jne isNotEqual
		mov al, bl 
		ret
	isNotEqual:
		inc esi 
		jmp findBegin
	findEnd:		
		ret
	@CharByIndex@8 endp
	@Max@8 proc
		xor ebp,ebp
        xor esi,esi
        xor edi,edi
	findBegin:
        xor edi,edi
		cmp edx,esi
        je findEnd
		mov ebx, [ecx][esi * 4]
	findBegin2:
        cmp edx,edi
        je findEnd2
        mov eax, [ebx][edi * 4]
        cmp ebp,eax
        jge jge1
        mov ebp, eax
    jge1:
        inc edi
        jmp findBegin2
	findEnd2:
        inc esi
		jmp findBegin
	findEnd:
        mov eax, ebp
   ret
 @Max@8 endp
end
