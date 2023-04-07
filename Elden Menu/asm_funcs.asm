extern statsBack:QWORD
extern dwVigorAddr:QWORD

extern runeBack:QWORD
extern dwRuneAddr:QWORD

extern levelBack:QWORD
extern dwLevelAddr:QWORD

extern fovBack:QWORD
extern fov:xmmword

extern noWeightBack:QWORD

extern runeMultiplierBack:QWORD
extern dwRuneMul:real4

extern playerHeightBack:QWORD
extern playerHeight_m128:xmmword
extern playerWidthBack:QWORD
extern playerWidth_m128:xmmword
extern playerLengthBack:QWORD
extern playerLength_m128:xmmword

.code
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

fovAsm_func proc
	movaps xmm0, [fov]
	jmp fovBack
fovAsm_func endp

noWeightAsm_func proc
	xorps xmm6, xmm6
	inc ebx
	cmp ebx, 05
	jmp noWeightBack
noWeightAsm_func endp

runeMultiplierAsm_func proc
	movss xmm0, [dwRuneMul]
	mulss xmm0, xmm1
	cvttss2si edi, xmm0
	jmp runeMultiplierBack
runeMultiplierAsm_func endp

playerHeightAsm_func proc
	movss xmm1, real4 ptr [playerHeight_m128]
	jmp playerHeightBack
playerHeightAsm_func endp

playerWidthAsm_func proc
	movss xmm2, real4 ptr [playerWidth_m128]
	jmp playerWidthBack
playerWidthAsm_func endp

playerLengthAsm_func proc
	movss xmm0, real4 ptr [playerLength_m128]
	jmp playerLengthBack
playerLengthAsm_func endp
end