# sumAll.s - program to calculate the sum of even and odd numbers entered by the user

.data
even_sum: .word 0 # variable to store the sum of even numbers
odd_sum: .word 0 # variable to store the sum of odd numbers

prompt: .asciiz "Please enter a number: "
str1: .asciiz "\nEven sum: "
str2: .asciiz "\nOdd sum: " 

.text
main:
  # Step 1: Initialize even_sum and odd_sum to 0
  li $t1, 0 # even_sum
  li $t2, 0 # odd_sum


loop:
  # Step 2: Prompt the user to enter a number
  li $v0, 4 # system call for printing a string
  la $a0, prompt # load the address of the prompt string
  syscall
  
  # Step 3: Read the input and store it in $t0
  li $v0, 5 # system call for reading an integer
  syscall
  move $t0, $v0

  # Step 4: If $t0 is 0, jump to step 9
  beq $t0, $zero, print_sums

  # Step 5: If $t0 is even, add it to even_sum and jump to step 7
  andi $t3, $t0, 1 # check if $t0 is odd or even
  beq $t3, $zero, add_even
  j add_odd
  
  
 # Step 6: If $t0 is odd, add it to odd_sum and jump to step 7
add_odd:
  add $t2, $t2, $t0 # add $t0 to odd_sum
  j loop

add_even:
  add $t1, $t1, $t0 # add $t0 to even_sum
  j loop


print_sums:
  li $v0, 4 # system call for printing a string
  la $a0, str1 # load the address of the even sum string
  syscall
  
  li $v0, 1 # system call for printing an integer
  move $a0, $t1 # load even_sum into $a0
  syscall

  li $v0, 4 # system call for printing a string
  la $a0, str2 # load the address of the odd sum string
  syscall

  li $v0, 1 # system call for printing an integer
  move $a0, $t2 # load odd_sum into $a0
  syscall

# Step 10: Exit the program
li      $v0, 10		
syscall