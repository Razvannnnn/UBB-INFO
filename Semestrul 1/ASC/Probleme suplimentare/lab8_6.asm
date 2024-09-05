bits 32

global start        

extern exit, fopen, fclose, fprintf, fread, printf
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll


segment data use32 class=data
    nume_fisier db "lab8_6.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd 0
    len equ 100
    text times len db 0
    lungime_sir dd 0
    cifra db 0
    frecv db 0
    
    mod_afisare_cif db "Cifra:%d", 10, 13, 0
    mod_afisare_frecv db "Frecventa:%d", 0

segment code use32 class=code
    start:
        ;DESCHIDERE FISIER
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptor_fisier], eax
        
        cmp eax, 0
        je final
        
        ;CITIM DIN FISIER
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        mov [lungime_sir], eax
        
        mov ecx, 10
        Repeta:
            push ecx
            
            mov ebx, '9'
            sub ebx, ecx
            
            mov esi, text
            mov ecx, [lungime_sir]
            mov edx, 0
            Repeta1:
                lodsb
                cmp al, bl
                jne next    
                inc edx
                next:
            loop Repeta1
            
            cmp edx, [frecv]
            jna next1
            
            mov byte[cifra], bl
            mov byte[frecv], dl
            
            next1:
            pop ecx
        loop Repeta
        
        push dword [cifra]
        push dword mod_afisare_cif
        call [printf]
        add esp, 4*2
        
        push dword [frecv]
        push dword mod_afisare_frecv
        call [printf]
        add esp, 4*2
        
        ;INCHIDEM FISIERUL
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        final:
        
        push    dword 0
        call    [exit]
