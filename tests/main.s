	.file	"main.c"
	.text
	.globl	dod
	.type	dod, @function
dod:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	fildl	-4(%ebp)
	leave
	ret
	.size	dod, .-dod
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, %eax
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
