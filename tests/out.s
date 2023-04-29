# {
# "globalST": [
# [
# "main","fun",
# "global",
# 0,
# 0,
# "int"
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
# "name":"main",
# "localST":[
# [
# "p","var",
# "local",
# 8,
# -8,
# "struct pair"
# ],
# [
# "q","var",
# "local",
# 8,
# -16,
# "struct pair"
# ],
# [
# "t0","var",
# "local",
# 4,
# -20,
# "struct pair*"
# ],
# [
# "t1","var",
# "local",
# 4,
# -24,
# "int*"
# ],
# [
# "t10","var",
# "local",
# 4,
# -64,
# "int*"
# ],
# [
# "t11","var",
# "local",
# 4,
# -68,
# "int"
# ],
# [
# "t2","var",
# "local",
# 4,
# -28,
# "struct pair*"
# ],
# [
# "t3","var",
# "local",
# 4,
# -32,
# "int*"
# ],
# [
# "t4","var",
# "local",
# 4,
# -36,
# "struct pair*"
# ],
# [
# "t5","var",
# "local",
# 8,
# -44,
# "struct pair"
# ],
# [
# "t6","var",
# "local",
# 4,
# -48,
# "struct pair*"
# ],
# [
# "t7","var",
# "local",
# 4,
# -52,
# "int*"
# ],
# [
# "t8","var",
# "local",
# 4,
# -56,
# "int"
# ],
# [
# "t9","var",
# "local",
# 4,
# -60,
# "struct pair*"
# ]
# ]
# }
# 
# ]
# }
# 
# *****************3A starts here**************
# .strlt0:
#	.string "p.x = %d, p.y = %d\n"
# main:
#	t0 = &q
#	t1 = t0 + 0
#	*t1 = 10
#	t2 = &q
#	t3 = t2 + 4
#	*t3 = 20
#	t4 = &q
#	t5 = *t4
#	p = t5
#	t6 = &p
#	t7 = t6 + 0
#	t8 = *t7
#	t9 = &p
#	t10 = t9 + 4
#	t11 = *t10
#	param t11
#	param t8
#	param .strlt0
#	call printf, 3
#	return 0

# ****************ASM Starts here********** 
