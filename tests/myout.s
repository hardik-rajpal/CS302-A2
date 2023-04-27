.strlt0:
	.string "p.x = %d, p.y = %d\n"
main:
	t0 = &p
	t1 = t0 + 0
	t1 = 10
	t3 = &p
	t4 = t3 + 4
	t4 = 20
	t6 = &p
	t7 = t6 + 0
	t9 = &p
	t10 = t9 + 4
	param t10
	param t7
	param .strlt0
	call printf, 3
	return 0

****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "p.x = %d, p.y = %d\n"
.text
.globl main
main:
	pushl %ebp
movl %esp, %ebp
subl $56, %esp
movl %ebp, %eax
add $-8, %eax
movl %eax, -12(%ebp)

	
	movl -12(%ebp), %eax
addl $0, %eax
movl %eax, -16(%ebp)

	movl $10, %eax
movl %eax, -16(%ebp)

	movl %ebp, %eax
add $-8, %eax
movl %eax, -24(%ebp)

	
	movl -24(%ebp), %eax
addl $4, %eax
movl %eax, -28(%ebp)

	movl $20, %eax
movl %eax, -28(%ebp)

	movl %ebp, %eax
add $-8, %eax
movl %eax, -36(%ebp)

	
	movl -36(%ebp), %eax
addl $0, %eax
movl %eax, -40(%ebp)

	movl %ebp, %eax
add $-8, %eax
movl %eax, -48(%ebp)

	
	movl -48(%ebp), %eax
addl $4, %eax
movl %eax, -52(%ebp)

	pushl -52(%ebp)
pushl -40(%ebp)
pushl $.strlt0
call printf
addl $4, %esp

	movl $0, %eax
movl %eax, 0(%ebp)
leave
ret

