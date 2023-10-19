; File: 101-hello_holbierton.asm
; Hello, Holberton followed by a new line.
; Desc: 64-bit assembly program that prints


extern printf
section .data
    format db "Hello, Holberton", 0
    printf_format db "%s", 10, 0

section .text
    global main

main:
    push rbp
    mov rdi, printf_format
    mov rsi, format
    mov rax, 0
    call printf
    pop rbp
    mov rax, 0
    ret
