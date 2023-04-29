# {
# "globalST": [
# [
# "main","fun",
# "global",
# 0,
# 0,
# ""
# ]
# ],
# "structs":[
# ],
# "functions":[
# {
# "name":"main",
# "localST":[
# [
# "t0","var",
# "local",
# 4,
# -12,
# "int"
# ],
# [
# "t1","var",
# "local",
# 4,
# -16,
# "int"
# ],
# [
# "t2","var",
# "local",
# 4,
# -20,
# "int"
# ],
# [
# "t3","var",
# "local",
# 4,
# -24,
# "int"
# ],
# [
# "t4","var",
# "local",
# 4,
# -28,
# "int"
# ],
# [
# "t5","var",
# "local",
# 4,
# -32,
# "int"
# ],
# [
# "t6","var",
# "local",
# 4,
# -36,
# "int"
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
# 
# ]
# }
# 
# *****************3A starts here**************
# .strlt0:
#	.string "%d %d\n"
# main:
#	x = 100
#	t0 = x + 1
#	y = t0
#	t1 = x NE_OP 100
#	t2 = y NE_OP 100
#	t3 = t1 OR_OP t2
#	x = t3
#	t4 = x * y
#	t5 = x + t4
#	t6 = y GT_OP 100
#	param t6
#	param t5
#	param .strlt0
#	call printf, 3
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "%d %d\n"
.text
# x = 100

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $36, %esp
movl $100, %eax
movl %eax, -4(%ebp)

# t0 = x + 1

movl -4(%ebp), %eax
addl $1, %eax
movl %eax, -12(%ebp)

# y = t0

movl -12(%ebp), %eax
movl %eax, -8(%ebp)

# t1 = x NE_OP 100

movl -4(%ebp), %eax
cmpl $100, %eax
setne %al
movzbl %al, %eax
movl %eax, -16(%ebp)

# t2 = y NE_OP 100

movl -8(%ebp), %eax
cmpl $100, %eax
setne %al
movzbl %al, %eax
movl %eax, -20(%ebp)

# t3 = t1 OR_OP t2

movl -16(%ebp), %eax
orl -20(%ebp), %eax
movl %eax, -24(%ebp)

# x = t3

movl -24(%ebp), %eax
movl %eax, -4(%ebp)

# t4 = x * y

movl -4(%ebp), %eax
imull -8(%ebp), %eax
movl %eax, -28(%ebp)

# t5 = x + t4

movl -4(%ebp), %eax
addl -28(%ebp), %eax
movl %eax, -32(%ebp)

# t6 = y GT_OP 100

movl -8(%ebp), %eax
cmpl $100, %eax
setg %al
movzbl %al, %eax
movl %eax, -36(%ebp)

# param t6

# param t5

# param .strlt0

# call printf, 3

subl $4, %esp
pushl -36(%ebp)
pushl -32(%ebp)
pushl $.strlt0
call printf
addl $16, %esp

# return 0

addl $36, %esp
leave
movl $0, %eax
ret
