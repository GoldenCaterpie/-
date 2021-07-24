.gba
.thumb
.create "test.gba",0x8000000
.close
.open "绿宝石.gba","test.gba", 0x8000000

.org 0x09700000
	b CleargHasWon
.pool
.importobj "build/linked.o"

.org 0x0813CB40
	ldr r3, =(NewFindMapsWithMon|1)
	bx r3
.pool

.org 0x08161CBC
	ldr r3, =(NewInitRoamer|1)
	bx r3
.pool

.org 0x08161D54
	ldr r3, =(NewRoamerMove|1)
	bx r3
.pool

.org 0x08161D00
	ldr r3, =(NewRoamerMoveToOtherLocationSet|1)
	bx r3
.pool

.org 0x08161EDC
	ldr r3, =(NewTryStartRoamerEncounter|1)
	bx r3
.pool

.org 0x08161F18
	ldr r3, =(NewUpdateRoamerHPStatus|1)
	bx r3
.pool

.org 0x08161F4C
	ldr r3, =(NewSetRoamerInactive|1)
	bx r3
.pool

.org 0x080B54C8 ;IsWildLevelAllowedByRepel
	mov r0, #1

.close
