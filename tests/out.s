# {
# "globalST": [
# [
# "bird","fun",
# "global",
# 0,
# 0,
# "struct ghosala"
# ],
# [
# "main","fun",
# "global",
# 0,
# 0,
# "struct ghosala"
# ],
# [
# "struct ghosala","struct",
# "global",
# 12,
# "-",
# "-"
# 
# ],
# [
# "struct pair","struct",
# "global",
# 8,
# "-",
# "-"
# 
# ]
# ],
# "structs":[
# {
# "name":"struct ghosala",
# "localST":[
# 
# [
# "eggs","var",
# "local",
# 4,
# 0,
# "int"
# ],
# [
# "koyal_koila","var",
# "local",
# 8,
# 4,
# "struct pair"
# ]
# ]
# }
# ,
# {
# "name":"struct pair",
# "localST":[
# 
# [
# "x","var",
# "local",
# 4,
# 0,
# "int"
# ],
# [
# "y","var",
# "local",
# 4,
# 4,
# "int"
# ]
# ]
# }
# 
# ],
# "functions":[
# {
# "name":"bird",
# "localST":[
# [
# "g","var",
# "local",
# 12,
# -12,
# "struct ghosala"
# ],
# [
# "t0","var",
# "local",
# 4,
# -16,
# "struct ghosala*"
# ],
# [
# "t1","var",
# "local",
# 4,
# -20,
# "int*"
# ],
# [
# "t2","var",
# "local",
# 4,
# -24,
# "struct ghosala*"
# ],
# [
# "t3","var",
# "local",
# 4,
# -28,
# "struct pair*"
# ],
# [
# "t4","var",
# "local",
# 4,
# -32,
# "int*"
# ],
# [
# "t5","var",
# "local",
# 4,
# -36,
# "int"
# ],
# [
# "t6","var",
# "local",
# 4,
# -40,
# "struct ghosala*"
# ],
# [
# "t7","var",
# "local",
# 4,
# -44,
# "struct pair*"
# ],
# [
# "t8","var",
# "local",
# 4,
# -48,
# "int*"
# ],
# [
# "t9","var",
# "local",
# 4,
# -52,
# "int"
# ],
# [
# "x","var",
# "param",
# 4,
# 8,
# "int"
# ]
# ],
# "ast":{
# "seq": [
# { "assignS": {
# "left": 
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "eggs"
# }
# }
# }
# ,
# "right": 
# {
# "identifier": "x"
# }
# }
# }
# ,
# { "assignS": {
# "left": 
# { "member": {
# "struct": 
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "koyal_koila"
# }
# }
# }
# ,
# "field": 
# {
# "identifier": "x"
# }
# }
# }
# ,
# "right": 
# { "op_binary": {
# "op": "MULT_INT"
# ,
# "left": 
# {
# "intconst": 2}
# ,
# "right": 
# {
# "identifier": "x"
# }
# }
# }
# }
# }
# ,
# { "assignS": {
# "left": 
# { "member": {
# "struct": 
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "koyal_koila"
# }
# }
# }
# ,
# "field": 
# {
# "identifier": "y"
# }
# }
# }
# ,
# "right": 
# { "op_binary": {
# "op": "MULT_INT"
# ,
# "left": 
# {
# "intconst": 3}
# ,
# "right": 
# {
# "identifier": "x"
# }
# }
# }
# }
# }
# ,
# {
# "return": 
# {
# "identifier": "g"
# }
# }
# 
# 
# ]
# }
# }
# ,
# {
# "name":"main",
# "localST":[
# [
# "g","var",
# "local",
# 12,
# -12,
# "struct ghosala"
# ],
# [
# "p","var",
# "local",
# 8,
# -20,
# "struct pair"
# ],
# [
# "t10","var",
# "local",
# 4,
# -24,
# "struct pair*"
# ],
# [
# "t11","var",
# "local",
# 4,
# -28,
# "int*"
# ],
# [
# "t12","var",
# "local",
# 4,
# -32,
# "struct pair*"
# ],
# [
# "t13","var",
# "local",
# 4,
# -36,
# "int*"
# ],
# [
# "t14","var",
# "local",
# 4,
# -40,
# "struct ghosala*"
# ],
# [
# "t15","var",
# "local",
# 4,
# -44,
# "int*"
# ],
# [
# "t16","var",
# "local",
# 4,
# -48,
# "struct ghosala*"
# ],
# [
# "t17","var",
# "local",
# 4,
# -52,
# "struct pair*"
# ],
# [
# "t18","var",
# "local",
# 4,
# -56,
# "struct ghosala*"
# ],
# [
# "t19","var",
# "local",
# 4,
# -60,
# "int*"
# ],
# [
# "t20","var",
# "local",
# 4,
# -64,
# "int"
# ],
# [
# "t21","var",
# "local",
# 4,
# -68,
# "struct ghosala*"
# ],
# [
# "t22","var",
# "local",
# 4,
# -72,
# "struct pair*"
# ],
# [
# "t23","var",
# "local",
# 4,
# -76,
# "int*"
# ],
# [
# "t24","var",
# "local",
# 4,
# -80,
# "int"
# ],
# [
# "t25","var",
# "local",
# 4,
# -84,
# "struct ghosala*"
# ],
# [
# "t26","var",
# "local",
# 4,
# -88,
# "struct pair*"
# ],
# [
# "t27","var",
# "local",
# 4,
# -92,
# "int*"
# ],
# [
# "t28","var",
# "local",
# 4,
# -96,
# "int"
# ]
# ],
# "ast":{
# "seq": [
# { "assignS": {
# "left": 
# { "member": {
# "struct": 
# {
# "identifier": "p"
# }
# ,
# "field": 
# {
# "identifier": "x"
# }
# }
# }
# ,
# "right": 
# {
# "intconst": 12}
# }
# }
# ,
# { "assignS": {
# "left": 
# { "member": {
# "struct": 
# {
# "identifier": "p"
# }
# ,
# "field": 
# {
# "identifier": "y"
# }
# }
# }
# ,
# "right": 
# {
# "intconst": 34}
# }
# }
# ,
# { "assignS": {
# "left": 
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "eggs"
# }
# }
# }
# ,
# "right": 
# {
# "intconst": 2}
# }
# }
# ,
# { "assignS": {
# "left": 
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "koyal_koila"
# }
# }
# }
# ,
# "right": 
# {
# "identifier": "p"
# }
# }
# }
# ,
# { "proccall": {
# "fname": 
# {
# "identifier": "printf"
# }
# ,
# "params": [
# { "member": {
# "struct": 
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "koyal_koila"
# }
# }
# }
# ,
# "field": 
# {
# "identifier": "y"
# }
# }
# }
# ,
# { "member": {
# "struct": 
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "koyal_koila"
# }
# }
# }
# ,
# "field": 
# {
# "identifier": "x"
# }
# }
# }
# ,
# { "member": {
# "struct": 
# {
# "identifier": "g"
# }
# ,
# "field": 
# {
# "identifier": "eggs"
# }
# }
# }
# ,
# {
# "stringconst": "g.eggs: %d, g.kk.x: %d, g.kk.y: %d\n"
# }
# 
# 
# ]
# }
# }
# ,
# {
# "return": 
# {
# "intconst": 0}
# }
# 
# 
# ]
# }
# }
# 
# ]
# }
# 
# *****************3A starts here**************
# .strlt0:
#	.string "g.eggs: %d, g.kk.x: %d, g.kk.y: %d\n"
# bird:
#	t0 = &g
#	t1 = t0 + 0
#	*t1 = x
#	t2 = &g
#	t3 = t2 + 4
#	t4 = t3 + 0
#	t5 = 2 * x
#	*t4 = t5
#	t6 = &g
#	t7 = t6 + 4
#	t8 = t7 + 4
#	t9 = 3 * x
#	*t8 = t9
#	return g
# main:
#	t10 = &p
#	t11 = t10 + 0
#	*t11 = 12
#	t12 = &p
#	t13 = t12 + 4
#	*t13 = 34
#	t14 = &g
#	t15 = t14 + 0
#	*t15 = 2
#	t16 = &g
#	t17 = t16 + 4
#	*t17 = p
#	t18 = &g
#	t19 = t18 + 0
#	t20 = *t19
#	t21 = &g
#	t22 = t21 + 4
#	t23 = t22 + 0
#	t24 = *t23
#	t25 = &g
#	t26 = t25 + 4
#	t27 = t26 + 4
#	t28 = *t27
#	param t28
#	param t24
#	param t20
#	param .strlt0
#	call printf, 4
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "g.eggs: %d, g.kk.x: %d, g.kk.y: %d\n"
.text
# t0 = &g

.globl bird
bird:
pushl %ebp
movl %esp, %ebp
subl $52, %esp
movl %ebp, %eax
add $-12, %eax
movl %eax, -16(%ebp)


# t1 = t0 + 0

movl -16(%ebp), %eax
addl $0, %eax
movl %eax, -20(%ebp)

# *t1 = x

movl 8(%ebp), %eax
movl -20(%ebp), %ebx
movl %eax, (%ebx)

# t2 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -24(%ebp)


# t3 = t2 + 4

movl -24(%ebp), %eax
addl $4, %eax
movl %eax, -28(%ebp)

# t4 = t3 + 0

movl -28(%ebp), %eax
addl $0, %eax
movl %eax, -32(%ebp)

# t5 = 2 * x

movl $2, %eax
imull 8(%ebp), %eax
movl %eax, -36(%ebp)

# *t4 = t5

movl -36(%ebp), %eax
movl -32(%ebp), %ebx
movl %eax, (%ebx)

# t6 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -40(%ebp)


# t7 = t6 + 4

movl -40(%ebp), %eax
addl $4, %eax
movl %eax, -44(%ebp)

# t8 = t7 + 4

movl -44(%ebp), %eax
addl $4, %eax
movl %eax, -48(%ebp)

# t9 = 3 * x

movl $3, %eax
imull 8(%ebp), %eax
movl %eax, -52(%ebp)

# *t8 = t9

movl -52(%ebp), %eax
movl -48(%ebp), %ebx
movl %eax, (%ebx)

# return g

addl $52, %esp
movl -12(%ebp), %eax
movl %eax, 12(%ebp)
movl -8(%ebp), %eax
movl %eax, 16(%ebp)
movl -4(%ebp), %eax
movl %eax, 20(%ebp)
leave
movl $0, %eax
ret
# t10 = &p

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $96, %esp
movl %ebp, %eax
add $-20, %eax
movl %eax, -24(%ebp)


# t11 = t10 + 0

movl -24(%ebp), %eax
addl $0, %eax
movl %eax, -28(%ebp)

# *t11 = 12

movl $12, %eax
movl -28(%ebp), %ebx
movl %eax, (%ebx)

# t12 = &p

movl %ebp, %eax
add $-20, %eax
movl %eax, -32(%ebp)


# t13 = t12 + 4

movl -32(%ebp), %eax
addl $4, %eax
movl %eax, -36(%ebp)

# *t13 = 34

movl $34, %eax
movl -36(%ebp), %ebx
movl %eax, (%ebx)

# t14 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -40(%ebp)


# t15 = t14 + 0

movl -40(%ebp), %eax
addl $0, %eax
movl %eax, -44(%ebp)

# *t15 = 2

movl $2, %eax
movl -44(%ebp), %ebx
movl %eax, (%ebx)

# t16 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -48(%ebp)


# t17 = t16 + 4

movl -48(%ebp), %eax
addl $4, %eax
movl %eax, -52(%ebp)

# *t17 = p

movl -20(%ebp), %eax
movl -52(%ebp), %ebx
movl %eax, (%ebx)

# t18 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -56(%ebp)


# t19 = t18 + 0

movl -56(%ebp), %eax
addl $0, %eax
movl %eax, -60(%ebp)

# t20 = *t19

movl -60(%ebp), %eax
movl (%eax), %eax
movl %eax, -64(%ebp)


# t21 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -68(%ebp)


# t22 = t21 + 4

movl -68(%ebp), %eax
addl $4, %eax
movl %eax, -72(%ebp)

# t23 = t22 + 0

movl -72(%ebp), %eax
addl $0, %eax
movl %eax, -76(%ebp)

# t24 = *t23

movl -76(%ebp), %eax
movl (%eax), %eax
movl %eax, -80(%ebp)


# t25 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -84(%ebp)


# t26 = t25 + 4

movl -84(%ebp), %eax
addl $4, %eax
movl %eax, -88(%ebp)

# t27 = t26 + 4

movl -88(%ebp), %eax
addl $4, %eax
movl %eax, -92(%ebp)

# t28 = *t27

movl -92(%ebp), %eax
movl (%eax), %eax
movl %eax, -96(%ebp)


# param t28

# param t24

# param t20

# param .strlt0

# call printf, 4

subl $4, %esp
pushl -96(%ebp)
pushl -80(%ebp)
pushl -64(%ebp)
pushl $.strlt0
call printf
addl $20, %esp

# return 0

addl $96, %esp
movl $0, %eax
movl %eax, 8(%ebp)
movl $0, %eax
movl %eax, 12(%ebp)
movl $0, %eax
movl %eax, 16(%ebp)
leave
movl $0, %eax
ret
