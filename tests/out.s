# {
# "globalST": [
# [
# "foo","fun",
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
# "name":"foo",
# "localST":[
# [
# "a","var",
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
# "int**"
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
# "int**"
# ],
# [
# "t3","var",
# "local",
# 4,
# -16,
# "int**"
# ],
# [
# "t4","var",
# "local",
# 4,
# -20,
# "int"
# ],
# [
# "t5","var",
# "local",
# 4,
# -24,
# "int**"
# ],
# [
# "t6","var",
# "local",
# 4,
# -28,
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
# 40,
# -40,
# "int[10]"
# ],
# [
# "i","var",
# "local",
# 4,
# -44,
# "int"
# ],
# [
# "t10","var",
# "local",
# 4,
# -96,
# "int"
# ],
# [
# "t11","var",
# "local",
# 40,
# -136,
# "int*[10]"
# ],
# [
# "t12","var",
# "local",
# 4,
# -140,
# "int"
# ],
# [
# "t13","var",
# "local",
# 40,
# -180,
# "int*[10]"
# ],
# [
# "t7","var",
# "local",
# 4,
# -48,
# "int"
# ],
# [
# "t8","var",
# "local",
# 4,
# -52,
# "int"
# ],
# [
# "t9","var",
# "local",
# 40,
# -92,
# "int*[10]"
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
# foo:
#	t0 = &a
#	t1 = 4 * 0
#	t2 = t0 + t1
#	*t2 = 2
#	t3 = &a
#	t4 = 4 * 0
#	t5 = t3 + t4
#	t6 = *t5
#	param t6
#	param .strlt0
#	call printf, 2
#	return 0
# main:
#	i = 0
# .for_cond_L2:
#	t7 = i LT_OP 10
#	if t7 goto .for_stmt_L4
#	goto .for_exit_L5
# .for_incrementor_L3:
#	t8 = i + 1
#	i = t8
#	goto .for_cond_L2
# .for_stmt_L4:
#	nop
#	t9 = &a
#	t10 = 4 * i
#	t11 = t9 + t10
#	*t11 = i
#	goto .for_incrementor_L3
# .for_exit_L5:
#	t13 = &a
#	param t13
#	t12 =  call foo, 1
#	param t12
#	param .strlt0
#	call printf, 2
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "%d\n"
.text
# t0 = &a

.globl foo
foo:
pushl %ebp
movl %esp, %ebp
subl $28, %esp
movl %ebp, %eax
add $8, %eax
movl %eax, -4(%ebp)


# t1 = 4 * 0

movl $4, %eax
imull $0, %eax
movl %eax, -8(%ebp)

# t2 = t0 + t1

movl -4(%ebp), %eax
addl -8(%ebp), %eax
movl %eax, -12(%ebp)

# *t2 = 2

movl $2, %eax
movl -12(%ebp), %ebx
movl %eax, (%ebx)

# t3 = &a

movl %ebp, %eax
add $8, %eax
movl %eax, -16(%ebp)


# t4 = 4 * 0

movl $4, %eax
imull $0, %eax
movl %eax, -20(%ebp)

# t5 = t3 + t4

movl -16(%ebp), %eax
addl -20(%ebp), %eax
movl %eax, -24(%ebp)

# t6 = *t5

movl -24(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -28(%ebp)


# param t6

# param .strlt0

# call printf, 2

subl $4, %esp
pushl -28(%ebp)
pushl $.strlt0
call printf
addl $12, %esp

# return 0

addl $28, %esp
movl $0, %eax
movl %eax, 12(%ebp)
leave
movl $0, %eax
ret
# i = 0

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $180, %esp
movl $0, %eax
movl %eax, -44(%ebp)

# t7 = i LT_OP 10

.for_cond_L2:
movl -44(%ebp), %eax
cmpl $10, %eax
setl %al
movzbl %al, %eax
movl %eax, -48(%ebp)

# if t7 goto .for_stmt_L4

movl -48(%ebp), %eax
cmpl $0, %eax
jne .for_stmt_L4

# goto .for_exit_L5

jmp .for_exit_L5

# t8 = i + 1

.for_incrementor_L3:
movl -44(%ebp), %eax
addl $1, %eax
movl %eax, -52(%ebp)

# i = t8

movl -52(%ebp), %eax
movl %eax, -44(%ebp)

# goto .for_cond_L2

jmp .for_cond_L2

# nop

.for_stmt_L4:
nop

# t9 = &a

movl %ebp, %eax
add $-40, %eax
movl %eax, -92(%ebp)


# t10 = 4 * i

movl $4, %eax
imull -44(%ebp), %eax
movl %eax, -96(%ebp)

# t11 = t9 + t10

movl -92(%ebp), %eax
addl -96(%ebp), %eax
movl %eax, -136(%ebp)

# *t11 = i

movl -136(%ebp), %ebx
movl -44(%ebp), %eax
movl %eax, 0(%ebx)

# goto .for_incrementor_L3

jmp .for_incrementor_L3

# t13 = &a

.for_exit_L5:
movl %ebp, %eax
add $-40, %eax
movl %eax, -180(%ebp)


# param t13

# t12 =  call foo, 1

subl $4, %esp
pushl -180(%ebp)
call foo
addl $4, %esp
movl 0(%esp), %eax
movl %eax, -140(%ebp)
addl $4, %esp

# param t12

# param .strlt0

# call printf, 2

subl $4, %esp
pushl -140(%ebp)
pushl $.strlt0
call printf
addl $12, %esp

# return 0

addl $180, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
movl $0, %eax
ret
