bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data

    a db 5
    d dw 25
    

; our code starts here
segment code use32 class=code
    start:
        ; 300-[5*(d-2*a)-1]
        
        mov AL, 2
        mov AH, [a]
        mul AH
        
        mov BX, [d]
        sub BX, AX
        
        mov AX, 0
        add AX, 5
        mul BX
        sub AX, 1
        
        mov BX, AX
        mov AX, 300
        sub AX, BX
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
