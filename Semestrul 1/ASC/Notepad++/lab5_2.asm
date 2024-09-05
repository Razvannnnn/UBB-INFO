bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 2, 1, 3, -3, -4, 2, -6
    la equ $-a
    b db 4, 5, -5, 7, -6, -2, 1
    lb equ $-b
    r times la+lb db 0

; our code starts here
segment code use32 class=code
    start:
        ; Se dau 2 siruri de octeti A si B. Sa se construiasca sirul R care sa contina doar elementele pare si negative din cele 2 siruri.
    
        mov ecx, la
        mov edx, 0
        mov esi, 0
        
        jecxz SfarsitA
        
        RepetaA:
            mov al, [a+esi]
            test al, 01h
            jne next
            cmp al, 0
            jge next
            
            mov [r+edx], al
            inc edx
            
            next:
            inc esi
            
        loop RepetaA
        
        SfarsitA:
        
        mov ecx, lb
        mov esi, 0
        
        jecxz SfarsitB
        
        RepetaB:
            mov al, [b+esi]
            test al, 01h
            jne next2
            cmp al, 0
            jge next2
            
            mov [r+edx], al
            inc edx
            
            next2:
            inc esi
            
        loop RepetaB
        
        SfarsitB:
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
