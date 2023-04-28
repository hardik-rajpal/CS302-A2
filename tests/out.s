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
# "dostuff","fun",
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
# "name":"dostuff",
# "localST":[
# [
# "a","var",
# "param",
# 4,
# 8,
# "int"
# ]
# ],
# "ast":{
# "seq": [
# { "proccall": {
# "fname": 
# {
# "identifier": "printf"
# }
# ,
# "params": [
# {
# "stringconst": "doing stuff\n"
# }
# 
# 
# ]
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
# ]
# ],
# "ast":{
# "seq": [
# { "proccall": {
# "fname": 
# {
# "identifier": "dostuff"
# }
# ,
# "params": [
# {
# "intconst": 1}
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
#	.string "doing stuff\n"
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
# dostuff:
#	param .strlt0
#	call printf, 1
# main:
#	param 1
#	call dostuff, 1
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "doing stuff\n"
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
# param .strlt0

.globl dostuff
dostuff:
# call printf, 1

pushl %ebp
movl %esp, %ebp
subl $0, %esp
subl $4, %esp
pushl $.strlt0
call printf
addl $8, %esp

# param 1

.globl main
main:
# call dostuff, 1

# return 0

pushl %ebp
movl %esp, %ebp
subl $32, %esp
addl $32, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
movl $0, %eax
ret
