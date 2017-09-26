.name "xor_DDR"
.comment "xor"

	live %1
	st r1, 200
	xor %1, %2, r1
	st r1, 300
