extern speedBack:QWORD
extern dwSpeed:QWORD

extern statsBack:QWORD
extern dwVigorAddr:QWORD

extern runeBack:QWORD
extern dwRuneAddr:QWORD

extern levelBack:QWORD
extern dwLevelAddr:QWORD

.code
speedAsm_func proc
	mov r12, dwSpeed
	cvtsi2ss xmm0,r12
	xor r12, r12
	jmp speedBack
speedAsm_func endp

vigorAsm_func proc
	push rax
	xor rax, rax
	lea rax, qword ptr [rbx+60]				; takes the address where the vigor variable is stored and put it in the rax register
	mov qword ptr [dwVigorAddr], rax		; than in in the declared c++ variable
	mov edi, dword ptr [rbx+60]
	test rcx, rcx
	pop rax
	jmp statsBack
vigorAsm_func endp

runeAsm_func proc
	push rax
	xor rax, rax
	lea rax, qword ptr [r14+108]			; takes the address where the rune amount variable is stored and put it in the rax register
	mov qword ptr [dwRuneAddr], rax			; than in in the declared c++ variable
	mov eax, dword ptr [r14+108]
	mov [rsi+240], eax
	pop rax
	jmp runeBack
runeAsm_func endp

levelAsm_func proc
	push rax
	xor rax, rax
	lea rax, qword ptr [rcx+104]			; takes the address where the level variable is stored and put it in the rax register
	mov qword ptr [dwLevelAddr], rax		; than in in the declared c++ variable
	mov ebx, dword ptr [rcx+104]
	cmp ebx, [rdi+928]
	pop rax
	jmp levelBack
levelAsm_func endp
end