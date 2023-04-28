.section .rodata
.strlt0:
	.string "z = %d\n"
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $10, %eax
movl %eax, -4(%ebp)

movl $3, %eax
movl %eax, -8(%ebp)

movl -4(%ebp), %eax
movl -8(%ebp), %ebx
movl $0, %edx
div %ebx
movl %eax, -16(%ebp)

movl -16(%ebp), %eax
movl %eax, -12(%ebp)

subl $4, %esp
pushl -12(%ebp)
pushl $.strlt0
call printf
addl $8, %esp

addl $16, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
call exit

