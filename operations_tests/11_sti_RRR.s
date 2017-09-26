.name "sti_RRR"
.comment "sti"

	live %1
	st r2, 900
	st r1, 800
	sti r2, r1, r2
	st r2, 950
