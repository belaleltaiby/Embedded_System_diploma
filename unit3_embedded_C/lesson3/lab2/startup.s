.section .vector

.word 	0x20001000   /*stack_top*/
.word 	_reset
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler
.word 	Vector_handler

.section .text
_reset:
	bl main
	b .
	
.thumb_func
Vector_handler:
	b _reset