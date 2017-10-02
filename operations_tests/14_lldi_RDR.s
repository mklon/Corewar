.name "lldi_RDR"
.comment "lldi"

	live %1
	st r2, 900
	st r1, 800
	lldi r1, %2, r2
	st r1, 925
	st r2, 950
