sleep:

POP r26
POP r27
POP r28
POP r29

	MOV		r21,	r28
sleep_1:
	MOV		r22,	r29
sleep_2:
	LDI		r23,	250
sleep_3:
	DEC		r23
	NOP
	BRNE	sleep_3

	DEC		r22
	BRNE	sleep_2

	DEC		r21
	BRNE	sleep_1

PUSH r27
PUSH r26

RET

set_and_sleep:
	OUT $18,r30
	OUT $12,r31
	PUSH r28
	PUSH r29
	RCALL sleep
RET
