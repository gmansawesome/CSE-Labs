.data
n:  .word 25

str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"

.text
main:
    li $v0, 5
    syscall

    la $t0, n
    lw $t0, 0($t0)

    # bge $v0, $t0, else
    # la $a0, str1
    # j print

    ble $v0, $t0, else
    la $a0, str3
    j print

# else:
    # la $a0, str4

else:
    la $a0, str2

print:
    li $v0, 4
    syscall

    li $v0, 10
    syscall
