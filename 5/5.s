.data
row01:  .space 16
row02:  .space 16
row03:  .space 16
row04:  .space 16

row11:  .space 16
row12:  .space 16
row13:  .space 16
row14:  .space 16

row21:  .space 16
row22:  .space 16
row23:  .space 16
row24:  .space 16

row31:  .space 16
row32:  .space 16
row33:  .space 16
row34:  .space 16

slice0: .word row01, row02, row03, row04
slice1: .word row11, row12, row13, row14
slice2: .word row21, row22, row23, row24
slice3: .word row31, row32, row33, row34

cube:   .word slice0, slice1, slice2, slice3
# etc. etc.

.text
.globl main
main:                        

#prologue
sw $fp, -4($sp)
la $fp, -4($sp)
sw $ra, -4($fp)
addi $sp, $sp, -8

#body
li $s0, 16;
li $s1, 0;
li $a0, 0;

loop1:
    bge $s1, $s0, loop1_end
    lw $s2, cube($s1)
    addi $t0, $s2, 16
    
    loop2:
        bge $s2, $t0, loop2_end
        lw $s3, ($s2)
        addi $t1, $s3, 16
        
        loop3:
            bge $s3, $t1, loop3_end
            lw $t2, ($s3)            
            bne $t2, $zero, skip
                addi $a0, $a0, 1
            skip:
            addi $s3, $s3, 4
            j loop3
        loop3_end:
        
        addi $s2, $s2, 4
        j loop2
    loop2_end:

    addi $s1, $s1, 4
    j loop1
loop1_end:

li $v0, 1
syscall

#epilogue

lw $ra, -4($fp)
la $sp, 4($fp)
lw $fp, ($fp)
jr $ra
