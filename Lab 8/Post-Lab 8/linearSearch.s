; Drew Goldman
; dag5wd
; 10/28/2020
; linearSearch.s
;
; Purpose : This file contains the implementation of the function
;           linearSearch, which will find an int in an array of integers
;
; Parameter 1 (in rdi) is a pointer to an int array
; Parameter 2 (in rsi) is an integer representing the size of the array
; Parameter 3 (in rdx) is an integer representing the target element to find in the array
; Return value int: the index in the array at which the target was found, or -1 if it wasn’t.
;

	global linearSearch

	section .text

linearSearch:
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers), and 
	; we are not using any callee-saved registers.

	; Subroutine body:
	mov 	rax, -1	 ; rax = -1
	xor	r10, r10	 ; i = 0
start:	
	cmp	r10, rsi	 ; if (i == n)
	je	done		 ; goto done
	mov	ecx, [rdi+4*r10]
	cmp	edx, ecx	 ; does a[i] == target?
	je	insert
	inc	r10		 ; i++
	jmp	start		 ; goto start

insert:
	mov	rax, r10
	jmp	done

done:	

	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret
