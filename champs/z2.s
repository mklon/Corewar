.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %0, %1
		ld 1, r2
		st r2, r3
		st r3, 250


live:	live %1
		zjmp %:live
		