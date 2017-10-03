.comment "Iі"
.name "not_alive"

s1: sti r2, %:live, %1
	and r1, %0, r1

live: live %1
		# zjmp %:live	
