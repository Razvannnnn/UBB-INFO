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
    b dw 14
    c dd 23
    d dq 45

; our code starts here
segment code use32 class=code
    start:
        ; (c+b)-a-(d+d) ; a - byte, b - word, c - double word, d - qword - Interpretare cu semn = 32-90 = -58
        
        mov bx, [c]
        mov cx, [c+2]
        mov ax, [b]
        cwd
        add ax, bx
        adc dx, cx ; dx:ax=c+b
        push(dx)
        push(ax) ; c+b in stiva
        mov al, [a]
        cbw
        cwd ; dx:ax=a
        pop(bx)
        pop(cx)
        sub bx, ax
        sbb cx, dx ; cx:bx=(c+b)-a
        push(cx)
        push(bx)
        pop(eax)
        cdq
        mov ebx, [d]
        add ebx, [d]
        mov ecx, [d+4]
        add ecx, [d+4]
        sub eax, ebx
        sbb edx, ecx
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
