.data

nrows: .word 6
ncols: .word 12
flag:  .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
       .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
       .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
       .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
       .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
       .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
						

.text
.globl main
main:                        

#prologue
sw $fp, -4($sp)
la $fp, -4($sp)
sw $ra, -4($fp)
sw $s0, -8($fp)
sw $s1, -12($fp)
sw $s2, -16($fp)
sw $s3, -20($fp)
addi $sp, $sp, -24

#body
lw $s2, nrows
lw $s3, ncols
li $s0, 0

loop1:
   bge $s0, $s2, loop1_end

   li $s1, 0

   loop2:
       bge $s1, $s3, loop2_end
           mul $t0, $s0, $s3
           add $t0, $t0, $s1
           lb $a0, flag($t0)            
           li $v0, 11
           syscall
	    
       addi $s1, $s1, 1
       j loop2
   loop2_end:
   
   li $a0,'\n'            
   li $v0, 11
   syscall

   addi $s0, $s0, 1
   j loop1
loop1_end:

#epilogue

lw $s3, -20($fp)
lw $s2, -16($fp)
lw $s1, -12($fp)
lw $s0, -8($fp)
lw $ra, -4($fp)
la $sp, 4($fp)
lw $fp, ($fp)
jr $ra
