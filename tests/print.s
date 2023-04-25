	.file	"print.c"
	.text
	.section	.rodata
.LC0:
	.string	"IIIII can print, sir, %d/%d.\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	$10
	pushl	$10
	pushl	$.LC0
	call	printf
	addl	$12, %esp
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
