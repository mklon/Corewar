.name "lldi_DRR"
.comment "lldi"

	live %1
	st r2, 900
	st r1, 800
	lldi %10, r1, r2
	st r1, 925
	st r2, 950
