.section .rodata
.strlt0:
	.string "%d\n"

.text
.globl main
main:
push %ebp 
movl %esp, %ebp

movl $44, %eax
movl $230, %ebx

cmpl $0, %eax
sete %al
movzbl %al, %eax 
cmpl $0, %ebx 
setne %bl 
movzbl %bl, %ebx
andl %eax, %ebx

pushl %ebx 
pushl $.strlt0
call printf
addl $8, %esp

leave
mov $0, %eax
ret