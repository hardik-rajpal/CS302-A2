foo:
	t0 = &p
	t1 = t0 + 0
	*t1 = 1
	t2 = &p
	t3 = t2 + 4
	*t3 = 2
	return p
main:
	t4 =  call foo, 0
	p = t4

****************ASM Starts here********** 
.section .rodata
.text
.globl foo
foo:
pushl %ebp
movl %esp, %ebp
subl $24, %esp
movl %ebp, %eax
add $-8, %eax
movl %eax, -12(%ebp)


movl -12(%ebp), %eax
addl $0, %eax
movl %eax, -16(%ebp)

movl $1, %eax
movl -16(%ebp), %ebx
movl %eax, (%ebx)

movl %ebp, %eax
add $-8, %eax
movl %eax, -20(%ebp)


movl -20(%ebp), %eax
addl $4, %eax
movl %eax, -24(%ebp)

movl $2, %eax
movl -24(%ebp), %ebx
movl %eax, (%ebx)

addl $24, %esp
movl -8(%ebp), %eax
movl %eax, 8(%ebp)
leave
ret

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
subl $4, %esp
call foo
addl $0, %esp
movl (%esp), %eax
movl %eax, -12(%ebp)
addl $4, %esp

movl -12(%ebp), %eax
movl %eax, -8(%ebp)

