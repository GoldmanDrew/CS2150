; Drew Goldman
; dag5wd
; 10/24/2020
; mathlib.s
;
; Purpose : This file contains the implementation of the functions
;          power and product, which computer the product and power of two integers
;
; Parameter 1 (in rdi) is the first integer
; Parameter 2 (in rsi) is the second integer
; Return value is an integer that is the product and the power
;

	global power
	global product

	section .text

product:
	;Standard prologue
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i

product_loop:
	cmp	r10, rsi	 ; does i == y?
	je	product_epilogue; if so, we are done with the loop
	add	rax, rdi 	 ; add x to rax
	inc	r10		 ; increment our counter i
	jmp	product_loop	 ; we are done with this loop iteration

product_epilogue:
	;Standard epilogue
	ret			;return to caller


; prologue
power:
	xor rax, rax		; zero out the return register
	mov rax, 0		; rax = 0
	inc rax		; rax++
	cmp rsi, 0		; if (y == 0) goto power_epilogue
	jle power_epilogue	; goto power_epilogue
	
	
	dec rsi		; y--
	call power		; recursion
	mov rsi, rax		; store recursive calls in y
	call product		; multiplication
	
power_epilogue:
	ret			;return to caller
