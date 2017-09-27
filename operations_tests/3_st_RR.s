.name "st_RR"
.comment "st"

	live %1
	ld %55, r2
	ld %56, r3
	st r2, 100
	st r3, 150
	st r2, r3
	st r2, 200
	st r3, 250
