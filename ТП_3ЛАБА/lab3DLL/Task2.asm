.MODEL FLAT, C
.CODE
Task2 PROC D1:dword, D2:dword
	mov eax,dword ptr [ebp+8]	; извлечение первого операнда
	mov ebx,dword ptr [ebp+12]	; извлечение второго операнда
	mul eax,ebx
	mov esi, dword ptr [ebp+16]; извлечение третьего операнда
 	mov [esi],eax 			; сохранение результата
	ret
Task2 ENDP
END