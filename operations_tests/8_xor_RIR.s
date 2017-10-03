.name "xor_RIR"
.comment "xor"

	live %1
	st r1, 200
	st r2, 220
	xor r1, 2, r2
	st r1, 300
	st r2, 320
