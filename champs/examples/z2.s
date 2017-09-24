.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r2, %0, %1
		ld 1, r2
		st r2, -150


live:	live %1
		ld %2, r4
		st r4, r5
		zjmp %:live
		