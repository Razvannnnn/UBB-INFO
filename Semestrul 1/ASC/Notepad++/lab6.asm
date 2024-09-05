bits 32 
global start        
extern exit ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll ; exit is a function that ends the calling process. It is defined in msvcrt.dll
; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
; our data is declared here (the variables needed by our program)
segment data use32 class=data

    s dw -22, 145, -48, 127
    ls equ ($-s)/2
	d times ls db 0

segment code use32 class=code

    ;Se da un sir de cuvinte s. Sa se construiasca sirul de octeti d, astfel incat d sa contina pentru fiecare pozitie din s:
    ;- numarul de biti de 0, daca numarul este negativ
    ;- numarul de biti de 1, daca numarul este pozitiv
    
    ;s: -22, 145, -48, 127
    
    ;Exemplu
    
    ; in binary:
    ; 1111111111101010, 10010001, 1111111111010000, 1111111
    ; d: 3, 3, 5, 7
    
    start:
        mov ecx, ls
        jecxz Sfarsit
        cld
        mov esi, s
        mov edi, d
        Repeta:
            push ecx
            lodsw
            mov ecx, 16
            mov bl,0
            cmp ax, 0
            jl negativ
            pozitiv:
                mov dl, 0
                jmp numara
            negativ:
                mov dl, 1
            numara:
                shl ax, 1
                adc bl, 0
            loop numara
            
            cmp dl, 0
            ja negativ2
            pozitiv2:
                mov al, bl
                jmp next
            negativ2:
                mov al, 16
                sub al, bl
                
            next:
            pop ecx
            stosb
        loop Repeta
    
    Sfarsit:
        
	push dword 0 ; push the parameter for exit onto the stack
	call [exit] ; call exit to terminate the program