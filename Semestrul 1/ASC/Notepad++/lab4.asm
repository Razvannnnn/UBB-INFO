bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    
    a db 11001011b
    b dw 1001011011001011b
    c db 0

; our code starts here
segment code use32 class=code
    start:
        ; Se dau un octet A si un cuvant B. Sa se obtina un octet C care are pe bitii 0-3 bitii 2-5 ai lui A, iar pe bitii 4-7 bitii 6-9 ai lui B.
          
        mov al, [a]
        mov bx, [b]
        mov cl, 2
        shl al, cl
        mov cl, 4
        shr al, cl
        mov cl, 6
        shl bx, cl
        mov cl, 5
        shr bx, cl
        mov cx, bx
        mov cl, al
        
        mov [c], cl
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
