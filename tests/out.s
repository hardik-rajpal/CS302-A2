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
# "n10","var",
# "local",
# 4,
# -36,
# "int"
# ],
# [
# "n11","var",
# "local",
# 4,
# -40,
# "int"
# ],
# [
# "n12","var",
# "local",
# 4,
# -44,
# "int"
# ],
# [
# "n3","var",
# "local",
# 4,
# -8,
# "int"
# ],
# [
# "n4","var",
# "local",
# 4,
# -12,
# "int"
# ],
# [
# "n5","var",
# "local",
# 4,
# -16,
# "int"
# ],
# [
# "n6","var",
# "local",
# 4,
# -20,
# "int"
# ],
# [
# "n7","var",
# "local",
# 4,
# -24,
# "int"
# ],
# [
# "n8","var",
# "local",
# 4,
# -28,
# "int"
# ],
# [
# "n9","var",
# "local",
# 4,
# -32,
# "int"
# ],
# [
# "result","var",
# "local",
# 4,
# -4,
# "int"
# ],
# [
# "t0","var",
# "local",
# 4,
# -48,
# "int"
# ],
# [
# "t1","var",
# "local",
# 4,
# -52,
# "int"
# ],
# [
# "t2","var",
# "local",
# 4,
# -56,
# "int"
# ],
# [
# "t3","var",
# "local",
# 4,
# -60,
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
#	.string "%d\n"
# main:
#	t0 = -300
#	n3 = t0
#	t1 = -3
#	n4 = t1
#	n5 = 1
#	n6 = 0
#	n7 = 1
#	n8 = 0
#	n9 = 0
#	n10 = 1
#	t2 = -30
#	n11 = t2
#	n12 = 0
#	t3 = n11 / 1
#	result = t3
#	param result
#	param .strlt0
#	call printf, 2
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "%d\n"
.text
# t0 = -300

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $60, %esp
movl $300, %eax
imull $-1, %eax
movl %eax, -48(%ebp)


# n3 = t0

movl -48(%ebp), %eax
movl %eax, -8(%ebp)

# t1 = -3

movl $3, %eax
imull $-1, %eax
movl %eax, -52(%ebp)


# n4 = t1

movl -52(%ebp), %eax
movl %eax, -12(%ebp)

# n5 = 1

movl $1, %eax
movl %eax, -16(%ebp)

# n6 = 0

movl $0, %eax
movl %eax, -20(%ebp)

# n7 = 1

movl $1, %eax
movl %eax, -24(%ebp)

# n8 = 0

movl $0, %eax
movl %eax, -28(%ebp)

# n9 = 0

movl $0, %eax
movl %eax, -32(%ebp)

# n10 = 1

movl $1, %eax
movl %eax, -36(%ebp)

# t2 = -30

movl $30, %eax
imull $-1, %eax
movl %eax, -56(%ebp)


# n11 = t2

movl -56(%ebp), %eax
movl %eax, -40(%ebp)

# n12 = 0

movl $0, %eax
movl %eax, -44(%ebp)

# t3 = n11 / 1

movl -40(%ebp), %eax
movl $1, %ecx
cltd
movl $0, %edx
idivl %ecx
movl %eax, -60(%ebp)

# result = t3

movl -60(%ebp), %eax
movl %eax, -4(%ebp)

# param result

# param .strlt0

# call printf, 2

subl $4, %esp
pushl -4(%ebp)
pushl $.strlt0
call printf
addl $12, %esp

# return 0

addl $60, %esp
leave
movl $0, %eax
ret
