bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fprintf, scanf, fclose, fopen
import exit msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dd 0
    b dd 0
    format_citire dd "%c", 0
    format_afisare_cat dd "Catul: %d ", 0
    format_afisare_rest dd "Restul: %d", 0
    
    cat dd 0
    res dd 0
    nume_fisier dd "adivb.txt", 0
    descriptor_fisier dd 0
    mod_acces dd "w", 9

; our code starts here
segment code use32 class=code
    start:
        ;CREARE FISIER
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4 * 2
        
        mov [descriptor_fisier], eax
        
        cmp eax, 0
        je Sfarsit
        
        push dword a
        push dword format_citire
        call [scanf]
        add esp, 4 * 2
        
        push dword b
        push dword format_citire
        call [scanf]
        add esp, 4 * 2
        
        mov ax, [a]
        sub ax, '0'
        mov bl, [b]
        sub bl, '0'
        div bl
        mov [cat], al
        mov [res], ah
        
        push dword [cat]
        push dword format_afisare_cat
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4 * 3
        
        push dword [res]
        push dword format_afisare_rest
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4 * 3
        
        ;INCHIDERE FISIER
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        Sfarsit:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
