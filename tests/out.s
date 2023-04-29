# {
# "globalST": [
# [
# "main","fun",
# "global",
# 0,
# 0,
# "int"
# ],
# [
# "print_numbers","fun",
# "global",
# 0,
# 0,
# "void"
# ]
# ],
# "structs":[
# ],
# "functions":[
# {
# "name":"main",
# "localST":[
# [
# "ptr1","var",
# "local",
# 4,
# -12,
# "int*"
# ],
# [
# "ptr2","var",
# "local",
# 4,
# -16,
# "int*"
# ],
# [
# "t11","var",
# "local",
# 4,
# -20,
# "int*"
# ],
# [
# "t12","var",
# "local",
# 4,
# -24,
# "int*"
# ],
# [
# "t13","var",
# "local",
# 4,
# -28,
# "int"
# ],
# [
# "t14","var",
# "local",
# 4,
# -32,
# "int*"
# ],
# [
# "t15","var",
# "local",
# 4,
# -36,
# "int*"
# ],
# [
# "x","var",
# "local",
# 4,
# -4,
# "int"
# ],
# [
# "y","var",
# "local",
# 4,
# -8,
# "int"
# ]
# ]
# }
# ,
# {
# "name":"print_numbers",
# "localST":[
# [
# "i","var",
# "local",
# 4,
# -4,
# "int"
# ],
# [
# "num_elements","var",
# "param",
# 4,
# 8,
# "int"
# ],
# [
# "start_ptr","var",
# "param",
# 4,
# 12,
# "int*"
# ],
# [
# "t0","var",
# "local",
# 4,
# -8,
# "int"
# ],
# [
# "t1","var",
# "local",
# 4,
# -12,
# "int"
# ],
# [
# "t10","var",
# "local",
# 4,
# -48,
# "int"
# ],
# [
# "t2","var",
# "local",
# 4,
# -16,
# "int"
# ],
# [
# "t3","var",
# "local",
# 4,
# -20,
# "int"
# ],
# [
# "t4","var",
# "local",
# 4,
# -24,
# "int"
# ],
# [
# "t5","var",
# "local",
# 4,
# -28,
# "int"
# ],
# [
# "t6","var",
# "local",
# 4,
# -32,
# "int"
# ],
# [
# "t7","var",
# "local",
# 4,
# -36,
# "int"
# ],
# [
# "t8","var",
# "local",
# 4,
# -40,
# "int"
# ],
# [
# "t9","var",
# "local",
# 4,
# -44,
# "int*"
# ]
# ]
# }
# 
# ]
# }
# 
# *****************3A starts here**************
# .strlt0:
#	.string "%d is even\n"
# .strlt1:
#	.string "%d is odd\n"
# print_numbers:
#	i = 0
# .while_cond_L1:
#	t0 = i LT_OP num_elements
#	if t0 goto .while_stmt_L2
#	goto .while_exit_L6
# .while_stmt_L2:
#	nop
#	t1 = *start_ptr
#	t2 = t1 / 2
#	t3 = t2 * 2
#	t4 = *start_ptr
#	t5 = t3 EQ_OP t4
#	if t5 goto .if_stmt_L3
#	goto .else_stmtL4
# .if_stmt_L3:
#	t6 = *start_ptr
#	param t6
#	param .strlt0
#	call printf, 2
#	goto .if_exit_L5
# .else_stmtL4:
#	nop
#	t7 = *start_ptr
#	param t7
#	param .strlt1
#	call printf, 2
# .if_exit_L5:
#	nop
#	t8 = 4 * 1
#	t9 = start_ptr - t8
#	start_ptr = t9
#	t10 = i + 1
#	i = t10
#	goto .while_cond_L1
# .while_exit_L6:
#	return
# main:
#	x = 10
#	y = 20
#	t11 = &x
#	ptr1 = t11
#	t12 = &y
#	ptr2 = t12
#	param 2
#	param ptr1
#	call print_numbers, 2
#	t13 = 4 * 1
#	t14 = ptr1 - t13
#	ptr1 = t14
#	*ptr1 = 15
#	t15 = &x
#	param 2
#	param t15
#	call print_numbers, 2
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "%d is even\n"
.strlt1:
	.string "%d is odd\n"
.text
# i = 0

.globl print_numbers
print_numbers:
pushl %ebp
movl %esp, %ebp
subl $48, %esp
movl $0, %eax
movl %eax, -4(%ebp)

# t0 = i LT_OP num_elements

.while_cond_L1:
movl -4(%ebp), %eax
cmpl 8(%ebp), %eax
setl %al
movzbl %al, %eax
movl %eax, -8(%ebp)

# if t0 goto .while_stmt_L2

movl -8(%ebp), %eax
cmpl $0, %eax
jne .while_stmt_L2

# goto .while_exit_L6

jmp .while_exit_L6

# nop

.while_stmt_L2:
nop

# t1 = *start_ptr

movl 12(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -12(%ebp)


# t2 = t1 / 2

movl -12(%ebp), %eax
movl $2, %ecx
cltd
idivl %ecx
movl %eax, -16(%ebp)

# t3 = t2 * 2

movl -16(%ebp), %eax
imull $2, %eax
movl %eax, -20(%ebp)

# t4 = *start_ptr

movl 12(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -24(%ebp)


# t5 = t3 EQ_OP t4

movl -20(%ebp), %eax
cmpl -24(%ebp), %eax
sete %al
movzbl %al, %eax
movl %eax, -28(%ebp)

# if t5 goto .if_stmt_L3

movl -28(%ebp), %eax
cmpl $0, %eax
jne .if_stmt_L3

# goto .else_stmtL4

jmp .else_stmtL4

# t6 = *start_ptr

.if_stmt_L3:
movl 12(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -32(%ebp)


# param t6

# param .strlt0

# call printf, 2

subl $4, %esp
pushl -32(%ebp)
pushl $.strlt0
call printf
addl $12, %esp

# goto .if_exit_L5

jmp .if_exit_L5

# nop

.else_stmtL4:
nop

# t7 = *start_ptr

movl 12(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -36(%ebp)


# param t7

# param .strlt1

# call printf, 2

subl $4, %esp
pushl -36(%ebp)
pushl $.strlt1
call printf
addl $12, %esp

# nop

.if_exit_L5:
nop

# t8 = 4 * 1

movl $4, %eax
imull $1, %eax
movl %eax, -40(%ebp)

# t9 = start_ptr - t8

movl 12(%ebp), %eax
subl -40(%ebp), %eax
movl %eax, -44(%ebp)

# start_ptr = t9

movl -44(%ebp), %eax
movl %eax, 12(%ebp)

# t10 = i + 1

movl -4(%ebp), %eax
addl $1, %eax
movl %eax, -48(%ebp)

# i = t10

movl -48(%ebp), %eax
movl %eax, -4(%ebp)

# goto .while_cond_L1

jmp .while_cond_L1

# return

.while_exit_L6:
addl $48, %esp
leave
movl $0, %eax
ret
# x = 10

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $36, %esp
movl $10, %eax
movl %eax, -4(%ebp)

# y = 20

movl $20, %eax
movl %eax, -8(%ebp)

# t11 = &x

movl %ebp, %eax
add $-4, %eax
movl %eax, -20(%ebp)


# ptr1 = t11

movl -20(%ebp), %eax
movl %eax, -12(%ebp)

# t12 = &y

movl %ebp, %eax
add $-8, %eax
movl %eax, -24(%ebp)


# ptr2 = t12

movl -24(%ebp), %eax
movl %eax, -16(%ebp)

# param 2

# param ptr1

# call print_numbers, 2

pushl -12(%ebp)
pushl $2
call print_numbers
addl $8, %esp

# t13 = 4 * 1

movl $4, %eax
imull $1, %eax
movl %eax, -28(%ebp)

# t14 = ptr1 - t13

movl -12(%ebp), %eax
subl -28(%ebp), %eax
movl %eax, -32(%ebp)

# ptr1 = t14

movl -32(%ebp), %eax
movl %eax, -12(%ebp)

# *ptr1 = 15

movl $15, %eax
movl -12(%ebp), %ebx
movl %eax, (%ebx)

# t15 = &x

movl %ebp, %eax
add $-4, %eax
movl %eax, -36(%ebp)


# param 2

# param t15

# call print_numbers, 2

pushl -36(%ebp)
pushl $2
call print_numbers
addl $8, %esp

# return 0

addl $36, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
movl $0, %eax
ret
