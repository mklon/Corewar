.name "nyatsulk_bot"
.comment "I will live forever"

l1:		sti r2, %0, %1
		ld 1, r2
		st r2, r6
		st r6, 900
		fork %5
		sti r5, %1, %1
		ld 1, r5
		st r7, r6
		st r8, 900

live:	live %1
		ld %2, r4
		st r4, r5
		zjmp %:live
