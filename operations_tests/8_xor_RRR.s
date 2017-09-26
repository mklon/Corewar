.name "xor_RRR"
.comment "xor"

	live %1
	st r1, 200
	st r2, 220
	st r3, 240
	xor r1, r2, r3
	st r1, 300
	st r2, 320
	st r3, 340

