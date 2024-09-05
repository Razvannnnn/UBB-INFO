bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, scanf, fprintf, fclose
import fopen msvcrt.dll; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll                         ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db "text2_2.txt", 0
    mod_acces db "w", 0
    descriptor_fisier dd 0
    format_afisare dd "%d ", 0
    
    nr dd 0
    format_nr db "%d", 0

; our code starts here
segment code use32 class=code
    start:
        ; 17. Se da un nume de fisier (definit in segmentul de date). Sa se creeze un fisier cu numele dat, apoi sa se citeasca de la tastatura numere si sa se scrie din valorile citite in fisier numerele divizibile cu 7, pana cand se citeste de la tastatura valoarea 0.
        
        ;CREARE FISIER
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptor_fisier], eax
        
        cmp eax, 0
        je Sfarsit
        
        ;CITIM NUMERE DE LA TASTATURA
        repeta:
            push dword nr
            push dword format_nr
            call [scanf]
            add esp, 4*2
        
            mov eax, [nr]
            mov edx, 0
            cmp eax, 0 
            je next
            mov ebx, 7
            div ebx                                     
            cmp edx, 0
            jne nu_diviz
            
            ;ADAUGARE IN FISIER NR DIV CU 7
            
            push dword [nr]
            push dword format_afisare
            push dword [descriptor_fisier]
            call [fprintf]
            add esp, 4*3

            nu_diviz:
            jmp repeta
        next:
        
        ;INCHIDERE FISIER
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4
        
        Sfarsit:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
