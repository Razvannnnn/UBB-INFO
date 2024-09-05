bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    r dd 10101010101010010110101001001100b
    t dd 11011110101010110011010101111010b
    q dd 0

; our code starts here
segment code use32 class=code
    start:
        ; Se dau 2 dublucuvinte R si T. Sa se obtina dublucuvantul Q astfel:
        ; bitii 0-6 din Q coincid cu bitii 10-16 a lui T
        ; bitii 7-24 din Q concid cu bitii obtinuti 7-24 in urma aplicarii R XOR T.
        ; bitii 25-31 din Q coincid cu bitii 5-11 a lui R.
        
        mov eax, [t]
        mov cl, 4
        shr eax, cl
        mov edx, eax
        
        mov eax, [r]
        mov ebx, [t]
        xor eax, ebx
        mov cl, 7
        shl eax, cl
        or edx, eax
        
        mov eax, [r]
        mov cl, 5
        shr eax, cl
        and eax, 00000000000000000000000011111111b
        mov cl, 7
        shl eax, 25
        or edx, eax
        
        mov [q], edx
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
