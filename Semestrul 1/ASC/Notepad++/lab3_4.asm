bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 7
    b dw 16
    c dd 23
    d dq 50

; our code starts here
segment code use32 class=code
    start:
        ;  (c+d-a)-(d-c)-b  ; a - byte, b - word, c - double word, d - qword - Interpretare cu semn ; rezultat = 23
        
        mov eax,[c]
        cdq
        add eax, [d]
        adc edx, [d+4]
        mov ebx,eax
        mov ecx,edx
        mov al,[a]
        cbw
        cwde
        cdq
        sub ebx,eax
        sbb ecx,edx
        mov eax,ebx
        mov edx,ecx
        push(edx) 
        push(eax) ;(c+d-a) se afla in stiva
        mov ebx, [d]
        mov ecx, [d+4]
        mov eax, [c]
        cdq
        sub ebx,eax
        sbb ecx,edx ; ecx:ebx=(d-c)
        pop(eax)
        pop(edx)
        sub eax,ebx
        sbb edx,ecx ; edx:eax=(c+d-a)-(d-c)
        mov ebx, eax
        mov ecx, edx
        mov ax, [b]
        cwde
        cdq
        sub ebx,eax
        sbb ecx,edx
        mov eax,ebx
        mov edx,ecx
             
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
