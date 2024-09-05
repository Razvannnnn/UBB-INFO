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
    format_afisare dd "Numar: %d", 0
    
    denumire_fisier dd "lab8_27.txt", 0
    mod_acces dd "a+", 0
    descriptor_fisier dd 0

    
    len equ 100
    text times len db 0
    lungime_sir dd 0
    
    numar dd 0
    zece dw 10

segment code use32 class=code
    start:
        ;DESCHIDEM FISIERUL
        push dword mod_acces
        push dword denumire_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je Sfarsit
        
        mov [descriptor_fisier], eax
        
        ;CITIM DIN FISIER
        
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        mov [lungime_sir], eax
        
        ;DETERMINAM NUMERELE
        
        mov ecx, [lungime_sir]
        mov esi, text
        
        mov ebx, 0
        mov eax, 0
        Repeta:
            mov eax, 0
            lodsb
            cmp al, '0'
            jb next
            cmp al, '9'
            ja next
            
            mul dword[zece]
            
            sub eax, '0'
            add ebx, eax
            jmp next2
            
            next:
                mov edx, 0 
                div dword[zece]
                mov ebx, eax
                cmp ebx, dword[numar]
                jb next1
                mov dword[numar], ebx
            next1:
                mov ebx, 0
            next2:
                
        loop Repeta
        
        ;AFISAM NUMARUL
        
        push dword [numar]
        push dword format_afisare
        push dword [descriptor_fisier]
        call [fprintf]
        add esp, 4*3
        
        ;INCHIDEM FISIERUL
        
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        Sfarsit:
        
        push    dword 0
        call    [exit]
