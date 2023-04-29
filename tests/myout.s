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
# "x","var",
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
# ]
# }
# 
# ]
# }
# 
# *****************3A starts here**************
# foo:
#	x = 5
# main:
#	call foo, 0

# ****************ASM Starts here********** 
.section .rodata
.text
# x = 5

.globl foo
foo:
pushl %ebp
movl %esp, %ebp
subl $4, %esp
movl $5, %eax
movl %eax, -4(%ebp)

# call foo, 0

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $0, %esp
call foo
addl $0, %esp

