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
    b db 7
    c db 6
    d db 4
    f dw 16
    h dw 10
    g dw 12

; our code starts here
segment code use32 class=code
    start:
        ; h/a + (2 + b) + f/d – g/c
        
        mov AX, [h]
        mov BL, [a]
        div BL
        
        mov CX, AX
        
        mov AX, [g]
        mov BL, [c]
        div BL
        
        mov DX, AX
        
        mov AX, [f]
        mov BL, [d]
        div BL
        
        add AX, CX
        add AX, 2
        add AX, [b]
        sub AX, DX
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
