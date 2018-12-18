.data
.text
.globl main

fib:
    addi $sp, $sp, -12
    sw $ra, 8($sp)
    sw $s0, 4($sp)
    sw $s1, 0($sp)

    add $s0, $0, $a0
    li $v0, 1
    ble $s0, 0x2 FibExit
    
    addi $a0, $s0, -1
    jal fib
    add $s1, $0, $v0

    addi $a0, $s0, -2
    jal fib
    add $v0, $v0, $s1

FibExit:
     lw $ra, 8($sp)
     lw $s0, 4($sp)
     lw $s1, 0($sp)
     addi $sp, $sp, 12
     jal $ra

main:
    li $a0, 6
    jal fib
    add $t0, $0, $v0
    li $v0, 10
    syscall
