bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 9
    b db 1
    c db 2
    d dd 10
    e dq 12

; our code starts here
segment code use32 class=code
    start:
        ; 2/(a+b*c-9)+e-d ; a,b,c-byte; d-doubleword; e-qword ; Interpretare fara semn ; rezulat = 2/2+2 = 3
        
        mov al, [b]
        mov bl, [c]
        mul bl ; ax=b*c
        mov bh, 0
        mov bl, [a]
        add ax, bx ; ax=a+b*c
        sub ax, 9 ; ax=a+b*c-9
        mov bx, ax
        mov ax, 0
        mov dx, 0
        add ax, 2
        div bx ; dx:ax/bx=ax=2/(a+b*c-9) , dx=2%(a+b*c-9)
        mov bx, ax
        mov eax, 0
        mov edx, 0
        mov ax, bx ; edx:eax=2/(a+b*c-9)
        mov ebx, [e]
        mov ecx, [e+4]
        add eax, ebx
        adc edx, ecx ; edx:eax=2/(a+b*c-9)+e
        mov ebx, [d]
        mov ecx, 0
        sub eax, ebx
        sbb ebx, edx ; edx:eax=2/(a+b*c-9)+e-d
        
        ; 2/(a+b*c-9)+e-d ; a,b,c-byte; d-doubleword; e-qword ; Interpretare cu semn
        
        ; mov al, [b]
        ; mov bl, [c]
        ; imul bl ; ax=b*c
        ; mov bx, ax ; bx=b*c
        ; mov al, [a]
        ; cbw
        ; sub ax, 9
        ; add bx, ax ; bx=a+b*c-9
        ; mov al, 2
        ; cbw
        ; cwd ; dx:ax=2
        ; idiv bx ; ax=2/(a+b*c-9)
        ; push(ax)
        ; mov eax, [d]
        ; cdq
        ; mov ebx, [e]
        ; mov ecx, [e+4]
        ; sub ebx, eax
        ; sbb ecx, edx ; ecx:ebx=e-d
        ; pop(ax)
        ; cwd
        ; cdq
        ; add eax, ebx
        ; adc edx, ecx ; edx:eax=2/(a+b*c-9)+e-d
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
