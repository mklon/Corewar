.name "xor_IRR"
.comment "xor"

	live %1
	st r1, 250
	st r2, 275
	xor 1, r1, r2
	st r1, 300
	st r2, 325
