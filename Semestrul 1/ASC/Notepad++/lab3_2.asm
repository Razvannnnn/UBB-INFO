bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data

    a db 15 
    b dw 14
    c dd 40
    d dq 21
    
; our code starts here
segment code use32 class=code
    start:
        ;(c+c-a)-(d+d)-b = 9 ; Interpretare fara semn 
        
        mov ebx, 0
        mov bl, [a]
        mov eax, [c]
        add eax, [c]
        sub eax, ebx ; eax=c+c-a
        push(eax)
        mov eax, [d]
        add eax, [d]
        mov edx, [d+4]
        adc edx, [d+4] ; edx:eax=d+d
        pop(ebx)
        mov ecx, 0
        sub ebx, eax
        sbb ecx, edx ; ecx:ebx=(c+c-a)-(d+d)
        mov eax, 0
        mov ax, [b]
        mov edx, 0
        sub ebx, eax
        sbb ecx, edx ; ecx:ebx=(c+c-a)-(d+d)-b
        mov eax, ebx
        mov edx, ecx
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
