; Drew Goldman
; dag5wd
; 11/5/2020
; binarySearch.s
;
; Purpose : This file contains the implementation of the function
;           binarySearch which will begin at the middle of a sorted array, 
;	    and continuously split the search space in half until it finds the 
;	    target element or reaches a point where it knows the target is not in the array.
;
; Parameter 1 (in rdi) is a pointer to an int array.
; Parameter 2 (in rsi) is an integer representing the beginning of the array.
; Parameter 3 (in rdx) is an integer representing the end of the array.
; Parameter 4 (in rcx) is an integer representing the target element to find in the array.
; Return value int: the index in the array at which the target was found, or -1 if it wasn’t.
;

	global binarySearch

	section .text

binarySearch:
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers), and 
	; we are not using any callee-saved registers.

	; Subroutine body:
	xor 	rax, rax	; rax = 0
	xor	r10, r10	; mid = 0
	
check:
	cmp	rsi, rdx	; cmp beginning to end
	jg	notFound	; if (beginning > end), goto notFound
	jl	midIndex	; if (beginning < end), goto midIndex
	je	found		; if (beginning = end), goto found
	
midIndex:
	mov	r10, rsi	; r10 = beginning
	add	r10, rdx	; r10 = beginning + end
	shr	r10, 1		; r10 /= 2 --> r10 = mid
	
	cmp	[rdi+4*r10], ecx ; cmp arr[mid] to key
	jg 	leftR		; if (arr[mid] > key), goto leftR
	jl	rightR		; if (arr[mid] < key), goto rightR
	je	found		; if (arr[mid] == key), goto found

leftR:
	dec	r10		; mid--
	mov	rdx, r10	; rdx = mid--
	jmp	check		; RECURSION

rightR:
	inc	r10		; mid++
	mov	rsi, r10	; rsi = mid++	
	jmp	check		; RECURSION

found:
	cmp	[rdi+4*r10], ecx ; cmp arr[mid] to key
	jne	notFound	; if (arr[mid] != key), goto notFound
	mov	rax, r10	; rax = index
	ret			; RETURN
	
notFound:
	mov	rax, -1	; rax = -1
	ret			; RETURN
