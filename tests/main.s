	.file	"main.c"
	.text
	.globl	dostuff
	; .type	dostuff, @function
dostuff:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	addl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	; .size	dostuff, .-dostuff
	.globl	getint
	; .type	getint, @function
getint:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$23, %eax
	popl	%ebp
	ret
	; .size	getint, .-getint
	.section	.rodata
.LC0:
	.string	"my mom loves me."
.LC1:
	.string	"and so does yours, %d/%d"
	.text
	.globl	main
	; .type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4016, %esp
	cmpl	$0, -12(%ebp)
	je	.L6
	cmpl	$0, -8(%ebp)
	je	.L6
	movl	$1, %eax
	jmp	.L7
.L6:
	movl	$0, %eax
.L7:
	movl	%eax, -16(%ebp)
	movl	-3080(%ebp), %eax
	movl	%eax, -4(%ebp)
	pushl	$4
	pushl	$2
	call	dostuff
	addl	$8, %esp
	movl	%eax, -12(%ebp)
	call	getint
	movl	%eax, -16(%ebp)
	pushl	$.LC0
	call	printf
	addl	$4, %esp
	pushl	$100
	pushl	$100
	pushl	$.LC1
	call	printf
	addl	$12, %esp
	movl	$0, -8(%ebp)
	jmp	.L8
.L16:
	movl	$0, -8(%ebp)
	jmp	.L10
.L14:
	cmpl	$0, -4(%ebp)
	jle	.L11
	cmpl	$0, -16(%ebp)
	jg	.L12
.L11:
	movl	-12(%ebp), %eax
	imull	-8(%ebp), %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	jmp	.L13
.L12:
	movl	-16(%ebp), %eax
	imull	%eax, %eax
	movl	%eax, %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
.L13:
	addl	$1, -8(%ebp)
.L10:
	cmpl	$5, -8(%ebp)
	jle	.L14
.L9:
	movl	-16(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jge	.L15
	movl	-16(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jle	.L15
	movl	-8(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jg	.L16
.L15:
	addl	$1, -8(%ebp)
.L8:
	cmpl	$6, -8(%ebp)
	jne	.L17
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jne	.L9
.L17:
	movl	-8(%ebp), %eax
	addl	%eax, -12(%ebp)
	movl	$0, %eax
	leave
	ret
	; .size	main, .-main
	; .ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	; .section	.note.GNU-stack,"",@progbits
