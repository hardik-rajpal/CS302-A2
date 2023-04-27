.strlt0:
	.string "p.x = %d, p.y = %d\n"
main:
	t0 = &p
	t1 = t0 + 0
	*t1 = 10
	t2 = &p
	t3 = t2 + 4
	*t3 = 20
	t4 = &p
	t5 = t4 + 0
	t6 = *t5
	t7 = &p
	t8 = t7 + 4
	t9 = *t8
	param t9
	param t6
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
subl $48, %esp
movl %ebp, %eax
add $-8, %eax
movl %eax, -12(%ebp)


movl -12(%ebp), %eax
addl $0, %eax
movl %eax, -16(%ebp)

movl $10, %eax
movl -16(%ebp), %ebx
movl %eax, (%ebx)

movl %ebp, %eax
add $-8, %eax
movl %eax, -20(%ebp)


movl -20(%ebp), %eax
addl $4, %eax
movl %eax, -24(%ebp)

movl $20, %eax
movl -24(%ebp), %ebx
movl %eax, (%ebx)

movl %ebp, %eax
add $-8, %eax
movl %eax, -28(%ebp)


movl -28(%ebp), %eax
addl $0, %eax
movl %eax, -32(%ebp)

movl -32(%ebp), %eax
movl (%eax), %eax
movl %eax, -36(%ebp)


movl %ebp, %eax
add $-8, %eax
movl %eax, -40(%ebp)


movl -40(%ebp), %eax
addl $4, %eax
movl %eax, -44(%ebp)

movl -44(%ebp), %eax
movl (%eax), %eax
movl %eax, -48(%ebp)


pushl -48(%ebp)
pushl -36(%ebp)
pushl $.strlt0
call printf
addl $4, %esp

movl $0, %eax
movl %eax, 0(%ebp)
leave
ret

