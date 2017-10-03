.name "lldi_DDR"
.comment "lldi"

	live %1
	st r2, 900
	st r1, 800
	lldi %10, %15, r2
	st r2, 950
