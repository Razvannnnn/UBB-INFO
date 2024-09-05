bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit
extern scanf   
extern printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll              ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 0
    b dw 0
    rezultat dw 0
    format_citire db "%d", "%d", 0
    format_afisare db "%d", 0

; our code starts here
segment code use32 class=code
    ;Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze a/b. Catul impartirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date). Valorile se considera cu semn.

    start:   
        push dword b
        push dword a
        push dword format_citire
        call [scanf]
        add esp, 4 * 3
        
        mov eax, [a]
        mov edx, 0
        mov ebx, [b]
        idiv ebx
        mov [rezultat], eax
        
        push dword [rezultat]
        push dword format_afisare
        call [printf]
        add esp, 4 * 2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
