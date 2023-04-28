.section .rodata
.strlt0:
	.string "%d, %d"
.text

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $72, %esp
movl %ebp, %eax
add $-8, %eax
movl %eax, -24(%ebp)



movl -24(%ebp), %eax
addl $0, %eax
movl %eax, -28(%ebp)


movl $10, %eax
movl -28(%ebp), %ebx
movl %eax, (%ebx)


movl %ebp, %eax
add $-8, %eax
movl %eax, -36(%ebp)



movl -36(%ebp), %eax
addl $4, %eax
movl %eax, -40(%ebp)


movl $12, %eax
movl -40(%ebp), %ebx
movl %eax, (%ebx)


movl -40(%ebp), %eax
movl %eax, -16(%ebp)
movl -36(%ebp), %eax
movl %eax, -12(%ebp)


movl %ebp, %eax
add $-16, %eax
movl %eax, -48(%ebp)



movl -48(%ebp), %eax
addl $0, %eax
movl %eax, -52(%ebp)


movl -52(%ebp), %eax
movl (%eax), %eax
movl %eax, -56(%ebp)



movl %ebp, %eax
add $-16, %eax
movl %eax, -64(%ebp)



movl -64(%ebp), %eax
addl $4, %eax
movl %eax, -68(%ebp)


movl -68(%ebp), %eax
movl (%eax), %eax
movl %eax, -72(%ebp)






subl $4, %esp
pushl -72(%ebp)
pushl -56(%ebp)
pushl $.strlt0
call printf
addl $8, %esp

leave 
call exit
