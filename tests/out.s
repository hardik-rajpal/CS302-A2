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
# 8,
# "int*"
# ],
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
# "int*"
# ],
# [
# "t2","var",
# "local",
# 4,
# -12,
# "int"
# ],
# [
# "t3","var",
# "local",
# 4,
# -16,
# "int"
# ],
# [
# "t4","var",
# "local",
# 4,
# -20,
# "int*"
# ],
# [
# "t5","var",
# "local",
# 4,
# -24,
# "int"
# ],
# [
# "t6","var",
# "local",
# 4,
# -28,
# "int*"
# ],
# [
# "t7","var",
# "local",
# 4,
# -32,
# "int"
# ],
# [
# "t8","var",
# "local",
# 4,
# -36,
# "int*"
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
# "int**"
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
# "t10","var",
# "local",
# 4,
# -84,
# "int"
# ],
# [
# "t11","var",
# "local",
# 4,
# -88,
# "int"
# ],
# [
# "t12","var",
# "local",
# 4,
# -92,
# "int"
# ],
# [
# "t13","var",
# "local",
# 64,
# -156,
# "int*[4][4]"
# ],
# [
# "t14","var",
# "local",
# 4,
# -160,
# "int"
# ],
# [
# "t15","var",
# "local",
# 64,
# -224,
# "int*[4][4]"
# ],
# [
# "t16","var",
# "local",
# 4,
# -228,
# "int"
# ],
# [
# "t17","var",
# "local",
# 64,
# -292,
# "int*[4][4]"
# ],
# [
# "t18","var",
# "local",
# 4,
# -296,
# "int"
# ],
# [
# "t19","var",
# "local",
# 4,
# -300,
# "int"
# ],
# [
# "t20","var",
# "local",
# 4,
# -304,
# "int"
# ],
# [
# "t21","var",
# "local",
# 4,
# -308,
# "int"
# ],
# [
# "t22","var",
# "local",
# 4,
# -312,
# "int"
# ],
# [
# "t23","var",
# "local",
# 64,
# -376,
# "int*[4][4]"
# ],
# [
# "t24","var",
# "local",
# 4,
# -380,
# "int"
# ],
# [
# "t25","var",
# "local",
# 64,
# -444,
# "int*[4][4]"
# ],
# [
# "t26","var",
# "local",
# 4,
# -448,
# "int"
# ],
# [
# "t27","var",
# "local",
# 64,
# -512,
# "int*[4][4]"
# ],
# [
# "t28","var",
# "local",
# 4,
# -516,
# "int"
# ],
# [
# "t29","var",
# "local",
# 64,
# -580,
# "int*[4][4]"
# ],
# [
# "t30","var",
# "local",
# 4,
# -584,
# "int"
# ],
# [
# "t31","var",
# "local",
# 64,
# -648,
# "int*[4][4]"
# ],
# [
# "t32","var",
# "local",
# 4,
# -652,
# "int"
# ],
# [
# "t33","var",
# "local",
# 4,
# -656,
# "int"
# ],
# [
# "t34","var",
# "local",
# 4,
# -660,
# "int"
# ],
# [
# "t35","var",
# "local",
# 4,
# -664,
# "int"
# ],
# [
# "t36","var",
# "local",
# 64,
# -728,
# "int*[4][4]"
# ],
# [
# "t37","var",
# "local",
# 4,
# -732,
# "int"
# ],
# [
# "t38","var",
# "local",
# 64,
# -796,
# "int*[4][4]"
# ],
# [
# "t39","var",
# "local",
# 4,
# -800,
# "int"
# ],
# [
# "t40","var",
# "local",
# 64,
# -864,
# "int*[4][4]"
# ],
# [
# "t41","var",
# "local",
# 4,
# -868,
# "int"
# ],
# [
# "t9","var",
# "local",
# 4,
# -80,
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
#	.string "%d"
# .strlt2:
#	.string "Foo:\n"
# .strlt1:
#	.string "\n"
# foo:
#	t0 = 4 * 3
#	t1 = a + t0
#	t2 = -1
#	*t1 = t2
#	t3 = 4 * 2
#	t4 = a + t3
#	*t4 = 0
#	t5 = 4 * 1
#	t6 = a + t5
#	*t6 = 1
#	t7 = 4 * 0
#	t8 = a + t7
#	*t8 = 0
#	return
# main:
#	i = 0
# .for_cond_L2:
#	t9 = i LT_OP 4
#	if t9 goto .for_stmt_L4
#	goto .for_exit_L9
# .for_incrementor_L3:
#	t10 = i + 1
#	i = t10
#	goto .for_cond_L2
# .for_stmt_L4:
#	nop
#	j = 0
# .for_cond_L5:
#	t11 = j LT_OP 4
#	if t11 goto .for_stmt_L7
#	goto .for_exit_L8
# .for_incrementor_L6:
#	t12 = j + 1
#	j = t12
#	goto .for_cond_L5
# .for_stmt_L7:
#	nop
#	t13 = &a
#	t14 = 16 * i
#	t15 = t13 + t14
#	t16 = 4 * j
#	t17 = t15 + t16
#	t18 = i + j
#	*t17 = t18
#	goto .for_incrementor_L6
# .for_exit_L8:
#	goto .for_incrementor_L3
# .for_exit_L9:
#	i = 0
# .for_cond_L10:
#	t19 = i LT_OP 4
#	if t19 goto .for_stmt_L12
#	goto .for_exit_L17
# .for_incrementor_L11:
#	t20 = i + 1
#	i = t20
#	goto .for_cond_L10
# .for_stmt_L12:
#	nop
#	j = 0
# .for_cond_L13:
#	t21 = j LT_OP 4
#	if t21 goto .for_stmt_L15
#	goto .for_exit_L16
# .for_incrementor_L14:
#	t22 = j + 1
#	j = t22
#	goto .for_cond_L13
# .for_stmt_L15:
#	nop
#	t23 = &a
#	t24 = 16 * i
#	t25 = t23 + t24
#	t26 = 4 * j
#	t27 = t25 + t26
#	t28 = *t27
#	param t28
#	param .strlt0
#	call printf, 2
#	goto .for_incrementor_L14
# .for_exit_L16:
#	param .strlt1
#	call printf, 1
#	goto .for_incrementor_L11
# .for_exit_L17:
#	param .strlt2
#	call printf, 1
#	t29 = &a
#	t30 = 16 * 3
#	t31 = t29 + t30
#	param t31
#	call foo, 1
#	i = 0
# .for_cond_L18:
#	t32 = i LT_OP 4
#	if t32 goto .for_stmt_L20
#	goto .for_exit_L25
# .for_incrementor_L19:
#	t33 = i + 1
#	i = t33
#	goto .for_cond_L18
# .for_stmt_L20:
#	nop
#	j = 0
# .for_cond_L21:
#	t34 = j LT_OP 4
#	if t34 goto .for_stmt_L23
#	goto .for_exit_L24
# .for_incrementor_L22:
#	t35 = j + 1
#	j = t35
#	goto .for_cond_L21
# .for_stmt_L23:
#	nop
#	t36 = &a
#	t37 = 16 * i
#	t38 = t36 + t37
#	t39 = 4 * j
#	t40 = t38 + t39
#	t41 = *t40
#	param t41
#	param .strlt0
#	call printf, 2
#	goto .for_incrementor_L22
# .for_exit_L24:
#	param .strlt1
#	call printf, 1
#	goto .for_incrementor_L19
# .for_exit_L25:
#	return 0

# ****************ASM Starts here********** 
.section .rodata
.strlt0:
	.string "%d"
.strlt2:
	.string "Foo:\n"
.strlt1:
	.string "\n"
.text
# t0 = 4 * 3

.globl foo
foo:
pushl %ebp
movl %esp, %ebp
subl $36, %esp
movl $4, %eax
imull $3, %eax
movl %eax, -4(%ebp)

# t1 = a + t0

movl 8(%ebp), %eax
addl -4(%ebp), %eax
movl %eax, -8(%ebp)

# t2 = -1

movl $1, %eax
imull $-1, %eax
movl %eax, -12(%ebp)


# *t1 = t2

movl -8(%ebp), %ebx
movl -12(%ebp), %eax
movl %eax, 0(%ebx)

# t3 = 4 * 2

movl $4, %eax
imull $2, %eax
movl %eax, -16(%ebp)

# t4 = a + t3

movl 8(%ebp), %eax
addl -16(%ebp), %eax
movl %eax, -20(%ebp)

# *t4 = 0

movl $0, %eax
movl -20(%ebp), %ebx
movl %eax, (%ebx)

# t5 = 4 * 1

movl $4, %eax
imull $1, %eax
movl %eax, -24(%ebp)

# t6 = a + t5

movl 8(%ebp), %eax
addl -24(%ebp), %eax
movl %eax, -28(%ebp)

# *t6 = 1

movl $1, %eax
movl -28(%ebp), %ebx
movl %eax, (%ebx)

# t7 = 4 * 0

movl $4, %eax
imull $0, %eax
movl %eax, -32(%ebp)

# t8 = a + t7

movl 8(%ebp), %eax
addl -32(%ebp), %eax
movl %eax, -36(%ebp)

# *t8 = 0

movl $0, %eax
movl -36(%ebp), %ebx
movl %eax, (%ebx)

# return

addl $36, %esp
leave
movl $0, %eax
ret
# i = 0

.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $868, %esp
movl $0, %eax
movl %eax, -72(%ebp)

# t9 = i LT_OP 4

.for_cond_L2:
movl -72(%ebp), %eax
cmpl $4, %eax
setl %al
movzbl %al, %eax
movl %eax, -80(%ebp)

# if t9 goto .for_stmt_L4

movl -80(%ebp), %eax
cmpl $0, %eax
jne .for_stmt_L4

# goto .for_exit_L9

jmp .for_exit_L9

# t10 = i + 1

.for_incrementor_L3:
movl -72(%ebp), %eax
addl $1, %eax
movl %eax, -84(%ebp)

# i = t10

movl -84(%ebp), %eax
movl %eax, -72(%ebp)

# goto .for_cond_L2

jmp .for_cond_L2

# nop

.for_stmt_L4:
nop

# j = 0

movl $0, %eax
movl %eax, -76(%ebp)

# t11 = j LT_OP 4

.for_cond_L5:
movl -76(%ebp), %eax
cmpl $4, %eax
setl %al
movzbl %al, %eax
movl %eax, -88(%ebp)

# if t11 goto .for_stmt_L7

movl -88(%ebp), %eax
cmpl $0, %eax
jne .for_stmt_L7

# goto .for_exit_L8

jmp .for_exit_L8

# t12 = j + 1

.for_incrementor_L6:
movl -76(%ebp), %eax
addl $1, %eax
movl %eax, -92(%ebp)

# j = t12

movl -92(%ebp), %eax
movl %eax, -76(%ebp)

# goto .for_cond_L5

jmp .for_cond_L5

# nop

.for_stmt_L7:
nop

# t13 = &a

movl %ebp, %eax
add $-64, %eax
movl %eax, -156(%ebp)


# t14 = 16 * i

movl $16, %eax
imull -72(%ebp), %eax
movl %eax, -160(%ebp)

# t15 = t13 + t14

movl -156(%ebp), %eax
addl -160(%ebp), %eax
movl %eax, -224(%ebp)

# t16 = 4 * j

movl $4, %eax
imull -76(%ebp), %eax
movl %eax, -228(%ebp)

# t17 = t15 + t16

movl -224(%ebp), %eax
addl -228(%ebp), %eax
movl %eax, -292(%ebp)

# t18 = i + j

movl -72(%ebp), %eax
addl -76(%ebp), %eax
movl %eax, -296(%ebp)

# *t17 = t18

movl -292(%ebp), %ebx
movl -296(%ebp), %eax
movl %eax, 0(%ebx)

# goto .for_incrementor_L6

jmp .for_incrementor_L6

# goto .for_incrementor_L3

.for_exit_L8:
jmp .for_incrementor_L3

# i = 0

.for_exit_L9:
movl $0, %eax
movl %eax, -72(%ebp)

# t19 = i LT_OP 4

.for_cond_L10:
movl -72(%ebp), %eax
cmpl $4, %eax
setl %al
movzbl %al, %eax
movl %eax, -300(%ebp)

# if t19 goto .for_stmt_L12

movl -300(%ebp), %eax
cmpl $0, %eax
jne .for_stmt_L12

# goto .for_exit_L17

jmp .for_exit_L17

# t20 = i + 1

.for_incrementor_L11:
movl -72(%ebp), %eax
addl $1, %eax
movl %eax, -304(%ebp)

# i = t20

movl -304(%ebp), %eax
movl %eax, -72(%ebp)

# goto .for_cond_L10

jmp .for_cond_L10

# nop

.for_stmt_L12:
nop

# j = 0

movl $0, %eax
movl %eax, -76(%ebp)

# t21 = j LT_OP 4

.for_cond_L13:
movl -76(%ebp), %eax
cmpl $4, %eax
setl %al
movzbl %al, %eax
movl %eax, -308(%ebp)

# if t21 goto .for_stmt_L15

movl -308(%ebp), %eax
cmpl $0, %eax
jne .for_stmt_L15

# goto .for_exit_L16

jmp .for_exit_L16

# t22 = j + 1

.for_incrementor_L14:
movl -76(%ebp), %eax
addl $1, %eax
movl %eax, -312(%ebp)

# j = t22

movl -312(%ebp), %eax
movl %eax, -76(%ebp)

# goto .for_cond_L13

jmp .for_cond_L13

# nop

.for_stmt_L15:
nop

# t23 = &a

movl %ebp, %eax
add $-64, %eax
movl %eax, -376(%ebp)


# t24 = 16 * i

movl $16, %eax
imull -72(%ebp), %eax
movl %eax, -380(%ebp)

# t25 = t23 + t24

movl -376(%ebp), %eax
addl -380(%ebp), %eax
movl %eax, -444(%ebp)

# t26 = 4 * j

movl $4, %eax
imull -76(%ebp), %eax
movl %eax, -448(%ebp)

# t27 = t25 + t26

movl -444(%ebp), %eax
addl -448(%ebp), %eax
movl %eax, -512(%ebp)

# t28 = *t27

movl -512(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -516(%ebp)


# param t28

# param .strlt0

# call printf, 2

subl $0, %esp
pushl -516(%ebp)
pushl $.strlt0
call printf
addl $8, %esp

# goto .for_incrementor_L14

jmp .for_incrementor_L14

# param .strlt1

.for_exit_L16:
# call printf, 1

subl $0, %esp
pushl $.strlt1
call printf
addl $4, %esp

# goto .for_incrementor_L11

jmp .for_incrementor_L11

# param .strlt2

.for_exit_L17:
# call printf, 1

subl $0, %esp
pushl $.strlt2
call printf
addl $4, %esp

# t29 = &a

movl %ebp, %eax
add $-64, %eax
movl %eax, -580(%ebp)


# t30 = 16 * 3

movl $16, %eax
imull $3, %eax
movl %eax, -584(%ebp)

# t31 = t29 + t30

movl -580(%ebp), %eax
addl -584(%ebp), %eax
movl %eax, -648(%ebp)

# param t31

# call foo, 1

pushl -648(%ebp)
call foo
addl $4, %esp

# i = 0

movl $0, %eax
movl %eax, -72(%ebp)

# t32 = i LT_OP 4

.for_cond_L18:
movl -72(%ebp), %eax
cmpl $4, %eax
setl %al
movzbl %al, %eax
movl %eax, -652(%ebp)

# if t32 goto .for_stmt_L20

movl -652(%ebp), %eax
cmpl $0, %eax
jne .for_stmt_L20

# goto .for_exit_L25

jmp .for_exit_L25

# t33 = i + 1

.for_incrementor_L19:
movl -72(%ebp), %eax
addl $1, %eax
movl %eax, -656(%ebp)

# i = t33

movl -656(%ebp), %eax
movl %eax, -72(%ebp)

# goto .for_cond_L18

jmp .for_cond_L18

# nop

.for_stmt_L20:
nop

# j = 0

movl $0, %eax
movl %eax, -76(%ebp)

# t34 = j LT_OP 4

.for_cond_L21:
movl -76(%ebp), %eax
cmpl $4, %eax
setl %al
movzbl %al, %eax
movl %eax, -660(%ebp)

# if t34 goto .for_stmt_L23

movl -660(%ebp), %eax
cmpl $0, %eax
jne .for_stmt_L23

# goto .for_exit_L24

jmp .for_exit_L24

# t35 = j + 1

.for_incrementor_L22:
movl -76(%ebp), %eax
addl $1, %eax
movl %eax, -664(%ebp)

# j = t35

movl -664(%ebp), %eax
movl %eax, -76(%ebp)

# goto .for_cond_L21

jmp .for_cond_L21

# nop

.for_stmt_L23:
nop

# t36 = &a

movl %ebp, %eax
add $-64, %eax
movl %eax, -728(%ebp)


# t37 = 16 * i

movl $16, %eax
imull -72(%ebp), %eax
movl %eax, -732(%ebp)

# t38 = t36 + t37

movl -728(%ebp), %eax
addl -732(%ebp), %eax
movl %eax, -796(%ebp)

# t39 = 4 * j

movl $4, %eax
imull -76(%ebp), %eax
movl %eax, -800(%ebp)

# t40 = t38 + t39

movl -796(%ebp), %eax
addl -800(%ebp), %eax
movl %eax, -864(%ebp)

# t41 = *t40

movl -864(%ebp), %eax
addl $0, %eax
movl (%eax), %eax
movl %eax, -868(%ebp)


# param t41

# param .strlt0

# call printf, 2

subl $0, %esp
pushl -868(%ebp)
pushl $.strlt0
call printf
addl $8, %esp

# goto .for_incrementor_L22

jmp .for_incrementor_L22

# param .strlt1

.for_exit_L24:
# call printf, 1

subl $0, %esp
pushl $.strlt1
call printf
addl $4, %esp

# goto .for_incrementor_L19

jmp .for_incrementor_L19

# return 0

.for_exit_L25:
addl $868, %esp
movl $0, %eax
movl %eax, 8(%ebp)
leave
movl $0, %eax
ret
