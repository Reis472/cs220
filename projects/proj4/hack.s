.globl main
main:
pop %rbp
push %rax
push %rsi
push %rdi
mov $0x64, %rdi
mov $11, %rbx
sub $1, %rbx
mov $0x602b80, %rsi
mov $0, %rax
mov %edi, 208(%rsi,%rax,4)
add $100, %rax
mov %edi, 208(%rsi,%rax,4)
add $100, %rax
mov %edi, 208(%rsi,%rax,4)
add $100, %rax
mov %edi, 208(%rsi,%rax,4)
add $100, %rax
mov %rbx, 208(%rsi,%rax,4)
add $100, %rax
mov %rbx, 208(%rsi,%rax,4)
add $100, %rax
mov %rbx, 208(%rsi,%rax,4)
add $100, %rax
mov %rbx, 208(%rsi,%rax,4)
add $100, %rax
mov %edi, 208(%rsi,%rax,4)
add $100, %rax
mov %edi, 208(%rsi,%rax,4)
add $100, %rax
mov %edi, 208(%rsi,%rax,4)
add $100, %rax
pop %rdi
pop %rsi
pop %rax
mov $0x400969, %rbx
jmp *%rbx
