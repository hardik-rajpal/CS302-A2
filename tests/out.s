# {
# "globalST": [
# [
# "foo","fun",
# "global",
# 0,
# 0,
# "void"
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
# "name":"foo",
# "localST":[
# [
# "b","var",
# "param",
# 4,
# 8,
# "int*"
# ],
# [
# "t0","var",
# "local",
# 4,
# -4,
# "int"
# ]
# ]
# }
# ,
# {
# "name":"main",
# "localST":[
# [
# "a","var",
# "local",
# 64,
# -64,
# "int[4][4]"
# ],
# [
# "b","var",
# "local",
# 4,
# -68,
# "int*"
# ],
# [
# "i","var",
# "local",
# 4,
# -72,
# "int"
# ],
# [
# "j","var",
# "local",
# 4,
# -76,
# "int"
# ],
# [
# "t1","var",
# "local",
# 64,
# -140,
# "int*[4][4]"
# ],
# [
# "t2","var",
# "local",
# 4,
# -144,
# "int"
# ],
# [
# "t3","var",
# "local",
# 64,
# -208,
# "int*[4][4]"
# ],
# [
# "t4","var",
# "local",
# 4,
# -212,
# "int"
# ],
# [
# "t5","var",
# "local",
# 4,
# -216,
# "int"
# ],
# [
# "t6","var",
# "local",
# 64,
# -280,
# "int*[4][4]"
# ],
# [
# "t7","var",
# "local",
# 4,
# -284,
# "int"
# ],
# [
# "t8","var",
# "local",
# 64,
# -348,
# "int*[4][4]"
# ],
# [
# "t9","var",
# "local",
# 4,
# -352,
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
#	.string "at b: %d\n"
# foo:
#	t0 = *b
#	param t0
#	param .strlt0
#	call printf, 2
#	return
# main:
#	t1 = &a
#	t2 = 16 * 2
#	t3 = t1 + t2
#	t4 = *t3
#	b = t4
#	t5 = *b
#	param t5
#	param .strlt0
#	call printf, 2
#	t6 = &a
#	t7 = 16 * 2
#	t8 = t6 + t7
#	t9 = *t8
#	param t9
#	call foo, 1
#	param b
#	call foo, 1
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "at b: %d\n"
.text
# t0 = *b

.globl foo
foo:
pushl %ebp
movl %esp, %ebp
subl $4, %esp
movl 8(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -4(%ebp)


# param t0

# param .strlt0

# call printf, 2

subl $0, %esp
pushl -4(%ebp)
pushl $.strlt0
call printf
addl $8, %esp

# return

addl $4, %esp
leave
movl $0, %eax
ret
# t1 = &a

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $352, %esp
movl %ebp, %eax
add $-64, %eax
movl %eax, -140(%ebp)


# t2 = 16 * 2

movl $16, %eax
imull $2, %eax
movl %eax, -144(%ebp)

# t3 = t1 + t2

movl -140(%ebp), %eax
addl -144(%ebp), %eax
movl %eax, -208(%ebp)

# t4 = *t3

movl -208(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -212(%ebp)


# b = t4

movl -212(%ebp), %eax
movl %eax, -68(%ebp)

# t5 = *b

movl -68(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -216(%ebp)


# param t5

# param .strlt0

# call printf, 2

subl $0, %esp
pushl -216(%ebp)
pushl $.strlt0
call printf
addl $8, %esp

# t6 = &a

movl %ebp, %eax
add $-64, %eax
movl %eax, -280(%ebp)


# t7 = 16 * 2

movl $16, %eax
imull $2, %eax
movl %eax, -284(%ebp)

# t8 = t6 + t7

movl -280(%ebp), %eax
addl -284(%ebp), %eax
movl %eax, -348(%ebp)

# t9 = *t8

movl -348(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -352(%ebp)


# param t9

# call foo, 1

pushl -352(%ebp)
call foo
addl $4, %esp

# param b

# call foo, 1

pushl -68(%ebp)
call foo
addl $4, %esp

# return 0

addl $352, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
movl $0, %eax
ret
