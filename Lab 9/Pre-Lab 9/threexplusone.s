; Drew Goldman
; dag5wd
; 10/30/2020
; threexplusone.s
; optimizations: used jnc to evaluate remainder, swaped idiv with shr to divide by 2
;
; Purpose : This file contains the implementation of the function
;           threexplusone that takes in a positive integer and returns the number of steps required for that integer to reach 1 by following the Collatz conjecture.
;
; Parameter 1 (in rdi) is a positive integer
; Return value int: number of steps required for input to reach 1 by following the Collatz conjecture.

	global threexplusone
	
	section .text

threexplusone:
	push rbp 		; push rbp
	mov edx, 0		; edx = 0
	mov rax, 0		; rax = 0
	mov rbp, rsp		; rbp = rsp
	cmp rdi, 1		; if (!(3x+1 == 1 (base case) ))
	jne txpo_r		; goto txpo_r
	jmp txpo_epilogue	; else goto end

txpo_r:
	mov edx, edi		; edx = rdi
	test edx, 1		; if (rdi % 2 == 0)
	jz if_even		; goto if_even
	push rdi		; push rdi
	imul rdi, 3		; 3x
	add rdi, 1		; 3x+1
	call threexplusone	; RECURSION
	add rax, 1		; counter++
	jmp txpo_epilogue	; goto txpo_epilogue

if_even:	
	push rdi		; push rdi
	shr rdi, 1		; x/2
	call threexplusone	; RECURSION
	add rax, 1		; counter++
	jmp txpo_epilogue	; goto txpo_epilogue

txpo_epilogue:
	mov rsp, rbp		; rsp = rbp --> revert
	pop rbp		; pop rbp
	ret			; RETURN counter
