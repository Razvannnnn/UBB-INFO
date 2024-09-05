bits 32

global start        

extern exit, scanf, printf, fopen, fclose, fread, fprintf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    nume_fisier db "lab8_28.txt", 0
    mod_acces db "w", 0
    descriptor_fisier db 0
    len equ 100
    text times len db 0 
    lungime_text db 0
    
    cuvant dd 0
    
    format_citire db "%s", 0

segment code use32 class=code
    start:
        ;deschidere fisier
        
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je Sfarsit
        
        mov [descriptor_fisier], eax
        
        ;citire de la tastatura
        Repeta:
            push dword cuvant
            push dword format_citire
            call [scanf]
            add esp, 4*2
            
            cmp cuvant, '$'
            je afara
            
            mov esi, cuvant
            
            repeta1:
                lodsb
                cmp al, 'a'
                jb next1
                cmp al, 'z'
                ja next1
                
            jmp repeta1
            
            jmp next
            
            ;adaugare cuvant
            
            push dword cuvant
            push dword format_afisare
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 4*3
            
            next:
            
        jmp Repeta
        
        afara:
           
        ;inchidere fisier
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
    
        Sfarsit:
        
        push    dword 0
        call    [exit]
