.name "zork"
.comment "I'M ALIIIIVE"

l2:		ldi %1, %1, r1
		st r1, 100
		# ld 513, r2
		# st r2, r3
		# st r3, 250


live:	live %1
		zjmp %:live
		