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
    c dd 30
    d dq 21

; our code starts here
segment code use32 class=code
    start:
        ; (b+b)+(c-a)+d ; Interpretare fara semn ; rezultat = 64
        
        mov eax, [d]
        mov edx, [d+4] ; edx:eax=d
        push(edx)
        push(eax) ; pe stiva este edx:eax=d
        mov eax, [c]
        mov ebx, 0
        mov bl, [a] ; ebx=a
        sub eax, ebx ; eax=c-a
        mov ebx, 0
        mov bx, [b]
        add bx, [b] ; ebx=b+b
        add eax,ebx
        mov edx, 0 ; edx:eax=(b+b)+(c-a)
        pop(ebx)
        pop(ecx)
        add eax, ebx
        adc edx, ecx ; edx:eax=(b+b)+(c-a)+d
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
