.data
.text
.globl main

main:
	addi $a0, $0, 6
	jal fact
	add $s1, $v0, $0
	li $v0, 10
	syscall
fact:
	addi $sp, $sp, -8
    sw $a0, 4($sp)
	sw $ra, 0($sp)
	bgt $a0, 0, L
	addi $v0, $0, 1
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	addi $sp, $sp, 8
	jr $ra

L:
	addi $a0, $a0, -1
	jal fact
	lw $ra, 0($sp)
	lw $a0, 4($sp)
	addi $sp, $sp, 8
	mult $v0, $a0
	mflo $v0
	jal $ra
