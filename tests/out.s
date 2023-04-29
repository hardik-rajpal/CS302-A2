# {
# "globalST": [
# [
# "abs","fun",
# "global",
# 0,
# 0,
# "int"
# ],
# [
# "main","fun",
# "global",
# 0,
# 0,
# "int"
# ]
# ],
# "structs":[
# ],
# "functions":[
# {
# "name":"abs",
# "localST":[
# [
# "t0","var",
# "local",
# 4,
# -4,
# "int"
# ],
# [
# "t1","var",
# "local",
# 4,
# -8,
# "int"
# ],
# [
# "t2","var",
# "local",
# 4,
# -12,
# "int"
# ],
# [
# "x","var",
# "param",
# 4,
# 8,
# "int"
# ]
# ]
# }
# ,
# {
# "name":"main",
# "localST":[
# [
# "t3","var",
# "local",
# 4,
# -8,
# "int"
# ],
# [
# "y","var",
# "local",
# 4,
# -4,
# "int"
# ]
# ]
# }
# 
# ]
# }
# 
# *****************3A starts here**************
# .strlt0:
#	.string "y: %d\n"
# abs:
#	t0 = x LT_OP 0
#	if t0 goto .if_stmt_L1
#	goto .else_stmtL2
# .if_stmt_L1:
#	t1 = -x
#	return t1
#	goto .if_exit_L3
# .else_stmtL2:
#	t2 = -x
#	x = t2
# .if_exit_L3:
#	nop
# main:
#	param 4
#	t3 =  call abs, 1
#	y = t3
#	param y
#	param .strlt0
#	call printf, 2
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "y: %d\n"
.text
# t0 = x LT_OP 0

.globl abs
abs:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
movl 8(%ebp), %eax
cmpl $0, %eax
setl %al
movzbl %al, %eax
movl %eax, -4(%ebp)

# if t0 goto .if_stmt_L1

movl -4(%ebp), %eax
cmpl $0, %eax
jne .if_stmt_L1

# goto .else_stmtL2

jmp .else_stmtL2

# t1 = -x

.if_stmt_L1:
movl 8(%ebp), %eax
imull $-1, %eax
movl %eax, -8(%ebp)


# return t1

addl $12, %esp
movl -8(%ebp), %eax
movl %eax, 12(%ebp)
leave
movl $0, %eax
ret
# goto .if_exit_L3

jmp .if_exit_L3

# t2 = -x

.else_stmtL2:
movl 8(%ebp), %eax
imull $-1, %eax
movl %eax, -12(%ebp)


# x = t2

movl -12(%ebp), %eax
movl %eax, 8(%ebp)

# nop

.if_exit_L3:
nop

# param 4

.globl main
main:
# t3 =  call abs, 1

pushl %ebp
movl %esp, %ebp
subl $8, %esp
subl $4, %esp
pushl $4
call abs
addl $4, %esp
movl 0(%esp), %eax
movl %eax, -8(%ebp)
addl $4, %esp

# y = t3

movl -8(%ebp), %eax
movl %eax, -4(%ebp)

# param y

# param .strlt0

# call printf, 2

subl $4, %esp
pushl -4(%ebp)
pushl $.strlt0
call printf
addl $12, %esp

# return 0

addl $8, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
movl $0, %eax
ret
