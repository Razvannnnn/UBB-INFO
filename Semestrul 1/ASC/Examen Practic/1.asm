bits 32

global start        

extern exit, scanf, printf, fopen, fclose, fprintf, fread    
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll


segment data use32 class=data
    mesaj1 db "c = ", 0
    mesaj2 db "n = ", 0
    
    c dw 0
    n dw 0
    nume dd 0
    
    format_citire_mesaj1 db "%c", 0
    format_citire_mesaj2 db "%d", 0
    format_citire_nume db "%s", 0
    
    mod_acces db "r", 0
    
    descriptor_fisier db 0
    len equ 100
    text times len db 0
    
    mesaj_afisare_incorect db "Incorect", 0
    mesaj_afisare_corect db "Numarul de aparitii al caracterului %c ", 0
    mesaj_afisare_corect2 db "urmat de un spatiu este egal cu numarul %d citit", 0
    
    lungime_fisier db 0


segment code use32 class=code
    start:
        push dword mesaj1
        call [printf]
        add esp, 4
        
        push dword c
        push dword format_citire_mesaj1
        call [scanf]
        add esp, 4*2
        
        push dword mesaj2
        call [printf]
        add esp, 4
        
        push dword n
        push dword format_citire_mesaj2
        call [scanf]
        add esp, 4*2
        
        push dword nume
        push dword format_citire_nume
        call [scanf]
        add esp, 4*2
        
        ;Deschidere fisier
        
        push dword mod_acces
        push dword nume
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je Sfarsit
        
        mov [descriptor_fisier], eax
        
        ;Citire din fisier
        
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        mov [lungime_fisier], eax
        
        mov esi, text
        mov ecx, [lungime_fisier]
        mov dx, [n]
        Repeta:
            lodsb
            cmp al, [c]
            jne next
            cmp byte[esi], 20h
            jne next
            
            dec dx
            
            next:
        loop Repeta
        
        cmp dx, 0
        jne incorect
        
        corect:
        
            push dword [c]
            push dword mesaj_afisare_corect
            call [printf]
            add esp, 4*2
            
            mov eax, 0
            mov ax, [n]
            
            push dword eax
            push dword mesaj_afisare_corect2
            call [printf]
            add esp, 4*2
            jmp next1
            
        incorect:
            push dword mesaj_afisare_incorect
            call [printf]
            add esp, 4
        
        next1:
        
        ;Inchidere fisier
        
        
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
    
        Sfarsit:
        
        push dword mesaj_afisare_incorect
        call [printf]
        add esp, 4
        
        push    dword 0
        call    [exit]
