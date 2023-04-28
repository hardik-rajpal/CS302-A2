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
# 16,
# "int"
# ],
# [
# "y","var",
# "param",
# 4,
# 12,
# "int"
# ],
# [
# "z","var",
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
# "identifier": "y"
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
# "identifier": "z"
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
# "a","var",
# "local",
# 4,
# -24,
# "int"
# ],
# [
# "b","var",
# "local",
# 4,
# -28,
# "int"
# ],
# [
# "c","var",
# "local",
# 4,
# -32,
# "int"
# ],
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
# 12,
# -44,
# "struct ghosala"
# ],
# [
# "t11","var",
# "local",
# 4,
# -48,
# "struct ghosala*"
# ],
# [
# "t12","var",
# "local",
# 4,
# -52,
# "int*"
# ],
# [
# "t13","var",
# "local",
# 4,
# -56,
# "int"
# ],
# [
# "t14","var",
# "local",
# 4,
# -60,
# "struct ghosala*"
# ],
# [
# "t15","var",
# "local",
# 4,
# -64,
# "struct pair*"
# ],
# [
# "t16","var",
# "local",
# 4,
# -68,
# "int*"
# ],
# [
# "t17","var",
# "local",
# 4,
# -72,
# "int"
# ],
# [
# "t18","var",
# "local",
# 4,
# -76,
# "struct ghosala*"
# ],
# [
# "t19","var",
# "local",
# 4,
# -80,
# "struct pair*"
# ],
# [
# "t20","var",
# "local",
# 4,
# -84,
# "int*"
# ],
# [
# "t21","var",
# "local",
# 4,
# -88,
# "int"
# ],
# [
# "t22","var",
# "local",
# 12,
# -100,
# "struct ghosala"
# ],
# [
# "t23","var",
# "local",
# 4,
# -104,
# "struct ghosala*"
# ],
# [
# "t24","var",
# "local",
# 4,
# -108,
# "struct pair*"
# ],
# [
# "t25","var",
# "local",
# 8,
# -116,
# "struct pair"
# ],
# [
# "t26","var",
# "local",
# 4,
# -120,
# "struct pair*"
# ],
# [
# "t27","var",
# "local",
# 4,
# -124,
# "int*"
# ],
# [
# "t28","var",
# "local",
# 4,
# -128,
# "int"
# ],
# [
# "t29","var",
# "local",
# 4,
# -132,
# "struct pair*"
# ],
# [
# "t30","var",
# "local",
# 4,
# -136,
# "int*"
# ],
# [
# "t31","var",
# "local",
# 4,
# -140,
# "int"
# ]
# ],
# "ast":{
# "seq": [
# { "assignS": {
# "left": 
# {
# "identifier": "c"
# }
# ,
# "right": 
# {
# "intconst": 1}
# }
# }
# ,
# { "assignS": {
# "left": 
# {
# "identifier": "a"
# }
# ,
# "right": 
# {
# "intconst": 3}
# }
# }
# ,
# { "assignS": {
# "left": 
# {
# "identifier": "g"
# }
# ,
# "right": 
# { "funcall": {
# "fname": 
# {
# "identifier": "bird"
# }
# ,
# "params": [
# {
# "intconst": 5}
# ,
# {
# "identifier": "a"
# }
# ,
# {
# "intconst": 1}
# 
# 
# ]
# }
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
# { "assignS": {
# "left": 
# {
# "identifier": "p"
# }
# ,
# "right": 
# { "member": {
# "struct": 
# { "funcall": {
# "fname": 
# {
# "identifier": "bird"
# }
# ,
# "params": [
# {
# "intconst": 5}
# ,
# {
# "identifier": "a"
# }
# ,
# {
# "intconst": 1}
# 
# 
# ]
# }
# }
# ,
# "field": 
# {
# "identifier": "koyal_koila"
# }
# }
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
# {
# "stringconst": "p.x: %d, p.y:%d\n"
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
# .strlt1:
#	.string "p.x: %d, p.y:%d\n"
# bird:
#	t0 = &g
#	t1 = t0 + 0
#	*t1 = x
#	t2 = &g
#	t3 = t2 + 4
#	t4 = t3 + 0
#	t5 = 2 * y
#	*t4 = t5
#	t6 = &g
#	t7 = t6 + 4
#	t8 = t7 + 4
#	t9 = 3 * z
#	*t8 = t9
#	return g
# main:
#	c = 1
#	a = 3
#	param 5
#	param a
#	param 1
#	t10 =  call bird, 3
#	g = t10
#	t11 = &g
#	t12 = t11 + 0
#	t13 = *t12
#	t14 = &g
#	t15 = t14 + 4
#	t16 = t15 + 0
#	t17 = *t16
#	t18 = &g
#	t19 = t18 + 4
#	t20 = t19 + 4
#	t21 = *t20
#	param t21
#	param t17
#	param t13
#	param .strlt0
#	call printf, 4
#	param 5
#	param a
#	param 1
#	t22 =  call bird, 3
#	t23 = &t22
#	t24 = t23 + 4
#	t25 = *t24
#	p = t25
#	t26 = &p
#	t27 = t26 + 0
#	t28 = *t27
#	t29 = &p
#	t30 = t29 + 4
#	t31 = *t30
#	param t31
#	param t28
#	param .strlt1
#	call printf, 3
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "g.eggs: %d, g.kk.x: %d, g.kk.y: %d\n"
.strlt1:
	.string "p.x: %d, p.y:%d\n"
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

movl 16(%ebp), %eax
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

# t5 = 2 * y

movl $2, %eax
imull 12(%ebp), %eax
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

# t9 = 3 * z

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
movl %eax, 20(%ebp)
movl -8(%ebp), %eax
movl %eax, 24(%ebp)
movl -4(%ebp), %eax
movl %eax, 28(%ebp)
leave
movl $0, %eax
ret
# c = 1

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $140, %esp
movl $1, %eax
movl %eax, -32(%ebp)

# a = 3

movl $3, %eax
movl %eax, -24(%ebp)

# param 5

# param a

# param 1

# t10 =  call bird, 3

subl $12, %esp
pushl $1
pushl -24(%ebp)
pushl $5
call bird
addl $12, %esp
movl 0(%esp), %eax
movl %eax, -44(%ebp)
movl 4(%esp), %eax
movl %eax, -40(%ebp)
movl 8(%esp), %eax
movl %eax, -36(%ebp)
addl $12, %esp

# g = t10

movl -44(%ebp), %eax
movl %eax, -12(%ebp)
movl -40(%ebp), %eax
movl %eax, -8(%ebp)
movl -36(%ebp), %eax
movl %eax, -4(%ebp)

# t11 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -48(%ebp)


# t12 = t11 + 0

movl -48(%ebp), %eax
addl $0, %eax
movl %eax, -52(%ebp)

# t13 = *t12

movl -52(%ebp), %eax
movl (%eax), %eax
movl %eax, -56(%ebp)


# t14 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -60(%ebp)


# t15 = t14 + 4

movl -60(%ebp), %eax
addl $4, %eax
movl %eax, -64(%ebp)

# t16 = t15 + 0

movl -64(%ebp), %eax
addl $0, %eax
movl %eax, -68(%ebp)

# t17 = *t16

movl -68(%ebp), %eax
movl (%eax), %eax
movl %eax, -72(%ebp)


# t18 = &g

movl %ebp, %eax
add $-12, %eax
movl %eax, -76(%ebp)


# t19 = t18 + 4

movl -76(%ebp), %eax
addl $4, %eax
movl %eax, -80(%ebp)

# t20 = t19 + 4

movl -80(%ebp), %eax
addl $4, %eax
movl %eax, -84(%ebp)

# t21 = *t20

movl -84(%ebp), %eax
movl (%eax), %eax
movl %eax, -88(%ebp)


# param t21

# param t17

# param t13

# param .strlt0

# call printf, 4

subl $4, %esp
pushl -88(%ebp)
pushl -72(%ebp)
pushl -56(%ebp)
pushl $.strlt0
call printf
addl $20, %esp

# param 5

# param a

# param 1

# t22 =  call bird, 3

subl $12, %esp
pushl $1
pushl -24(%ebp)
pushl $5
call bird
addl $12, %esp
movl 0(%esp), %eax
movl %eax, -100(%ebp)
movl 4(%esp), %eax
movl %eax, -96(%ebp)
movl 8(%esp), %eax
movl %eax, -92(%ebp)
addl $12, %esp

# t23 = &t22

movl %ebp, %eax
add $-100, %eax
movl %eax, -104(%ebp)


# t24 = t23 + 4

movl -104(%ebp), %eax
addl $4, %eax
movl %eax, -108(%ebp)

# t25 = *t24

movl -108(%ebp), %eax
movl (%eax), %eax
movl %eax, -116(%ebp)


# p = t25

movl -116(%ebp), %eax
movl %eax, -20(%ebp)
movl -112(%ebp), %eax
movl %eax, -16(%ebp)

# t26 = &p

movl %ebp, %eax
add $-20, %eax
movl %eax, -120(%ebp)


# t27 = t26 + 0

movl -120(%ebp), %eax
addl $0, %eax
movl %eax, -124(%ebp)

# t28 = *t27

movl -124(%ebp), %eax
movl (%eax), %eax
movl %eax, -128(%ebp)


# t29 = &p

movl %ebp, %eax
add $-20, %eax
movl %eax, -132(%ebp)


# t30 = t29 + 4

movl -132(%ebp), %eax
addl $4, %eax
movl %eax, -136(%ebp)

# t31 = *t30

movl -136(%ebp), %eax
movl (%eax), %eax
movl %eax, -140(%ebp)


# param t31

# param t28

# param .strlt1

# call printf, 3

subl $4, %esp
pushl -140(%ebp)
pushl -128(%ebp)
pushl $.strlt1
call printf
addl $16, %esp

# return 0

addl $140, %esp
movl $0, %eax
movl %eax, 8(%ebp)
movl $0, %eax
movl %eax, 12(%ebp)
movl $0, %eax
movl %eax, 16(%ebp)
leave
movl $0, %eax
ret
