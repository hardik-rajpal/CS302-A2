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
# "a","var",
# "param",
# 4,
# 16,
# "int"
# ],
# [
# "b","var",
# "param",
# 4,
# 12,
# "int"
# ],
# [
# "c","var",
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
# "a","var",
# "local",
# 4,
# -4,
# "int"
# ],
# [
# "b","var",
# "local",
# 4,
# -8,
# "int"
# ],
# [
# "c","var",
# "local",
# 4,
# -12,
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
#	.string "a = %d, b = %d, c = %d"
# foo:
#	param c
#	param b
#	param a
#	param .strlt0
#	call printf, 4
#	return
# main:
#	a = 3
#	b = 23
#	c = 111
#	param c
#	param b
#	param a
#	call foo, 3
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "a = %d, b = %d, c = %d"
.text
# param c

.globl foo
foo:
# param b

# param a

# param .strlt0

# call printf, 4

pushl %ebp
movl %esp, %ebp

subl $0, %esp

subl $4, %esp
pushl 8(%ebp)
pushl 12(%ebp)
pushl 16(%ebp)
pushl $.strlt0
call printf
addl $20, %esp

# return

addl $0, %esp
leave
movl $0, %eax
ret
# a = 3

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
movl $3, %eax
movl %eax, -4(%ebp)

# b = 23

movl $23, %eax
movl %eax, -8(%ebp)

# c = 111

movl $111, %eax
movl %eax, -12(%ebp)

# param c

# param b

# param a

# call foo, 3

pushl -4(%ebp)
pushl -8(%ebp)
pushl -12(%ebp)
call foo
addl $12, %esp

# return 0

addl $12, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
movl $0, %eax
ret
