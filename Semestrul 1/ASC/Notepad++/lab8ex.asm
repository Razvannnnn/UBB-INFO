bits 32 

global start        

extern exit       
extern fopen        
extern fclose
extern fread
extern printf
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "input.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd 0
    
    text resb 1000
    count dd 100
    dimensiune dd 1
    
    lungime_sir dd 0
    cifra_min db 10
    
    format_afisare db "%u", 0
    mod_acces dd "w", 0
    
    
; our code starts here
segment code use32 class=code
    start:
        ;DESCHIDERE FISIER
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4 * 2
        
        cmp eax, 0
        je final        ; NU S-A PUTUT DESCHIDE FISIERUL
        
        
        ; Salvam descriptorul pentru a-l utiliza mai tarziu
        mov [descriptor_fisier], eax
        
        
        ; Acces la continutul fisierului 
        push dword [descriptor_fisier]  ;CITIRE DIN FISIER
        push dword [count]
        push dword [dimensiune]
        push dword text
        call [fread]
        add esp, 4 * 4
        
        ; Parcurgerea unui sir de numere si calcularea nr de cifre impare din el
        mov [lungime_sir], eax
        
        mov esi, sir
        mov ecx, [lungime_sir]
        cld
        jecxz final_bucla
        
        bucla:
            lodsb           ; AL <- sir[i]
            sub al, '0'
            test al, 1
            jz salt
            
            cmp al, [cifra_min]
            ja salt
            
            mov [cifra_min], al
            
            salt:
        loop bucla
        
        final_bucla:
        
        ; AFISARE PE ECRAN
        mov eax, 0
        mov al, [cifra_min]
        
        push eax
        push dword format_afisare
        call [printf]
        add esp, 4 * 2
        
        ;INCHIDERE FISIER
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        final:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
