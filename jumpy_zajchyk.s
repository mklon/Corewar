.name "jumpy_zajchyk"
.comment "I will live forever"

l1:		live %1
		sti r1, %:live, %1
		fork %:fork

live:	live %1
		zjmp %:l1

fork:	live %1
		ld %0, r4
		fork %:live
		live %1
