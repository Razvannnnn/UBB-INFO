bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fclose, printf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll                 ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "text2_1.txt", 0
    mod_acces db "r", 0
    descriptor_fisier dd 0
    mesaj_afisare dd "Nr. consoane: %d", 0
    
    text resb 1000
    count dd 100
    dimensiune dd 1
    
    lungime_sir dd 0
    nr_consoane dd 0

; our code starts here
segment code use32 class=code
    start:
        ; 2. Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de consoane si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.
        
        
        ;DESCHIDERE FISIER
        push dword mod_acces        
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0  ;DACA FISIERUL NU EXISTA SARE LA SFARSIT
        je Sfarsit
        mov [descriptor_fisier], eax
        
        ;CITIRE DIN FISIER
        push dword [descriptor_fisier]
        push dword [count]
        push dword [dimensiune]
        push dword text
        call [fread]
        add esp, 4*4
        
        mov [lungime_sir], eax
        
        ;DETERMINARE NR CONSOANE
        mov esi, text
        mov ecx, [lungime_sir]
        mov ebx, 0
        cld
        jecxz Sfarsit_loop 
        repeta:
            lodsb
            sub al, 'a'     ;sau cmp cu 'a','e','i','o','u'
            cmp al, 0
            je Vocala
            cmp al, 4
            je Vocala
            cmp al, 8
            je Vocala
            cmp al, 14
            je Vocala
            cmp al, 20
            je Vocala
            
            inc ebx
            
            Vocala:
            
        loop repeta
        
        mov [nr_consoane], ebx
        
        Sfarsit_loop:
        
        ;AFISARE NR CONSOANE
        push dword [nr_consoane]
        push dword mesaj_afisare
        call [printf]
        add esp, 4*2
        
        Sfarsit:
        
        ;INCHIDERE FISIER
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
