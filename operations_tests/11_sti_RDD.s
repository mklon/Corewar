.name "sti_RDD"
.comment "sti"

	live %1
	ld 255 r2
	st r2, 190
	st r1, 190
	sti r2, r1, r2
	# st r2, 300
