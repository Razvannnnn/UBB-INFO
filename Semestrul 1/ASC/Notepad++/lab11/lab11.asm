bits 32

global start

extern exit, scanf, printf, modul   
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    format_afisare_cu db "Cu semn: -%d ", 10, 13, 0
    format_afisare_fara db "Fara semn: %d ", 0

    format_citire db "%x", 0
    mesaj_citire db "Sirul de numere: ", 0
    
    nr dd 0
    max equ 50
    sir times max+1 dd 0

segment code use32 class=code
    
    
    start:
        ;9. Se cere sa se citeasca de la tastatura un sir de numere, date in baza 16 (se citeste de la tastatura un sir de caractere si in memorie trebuie stocat un sir de numere). Sa se afiseze valoarea zecimala a nr atat ca numere fara semn cat si ca numere cu semn.
         
        push dword mesaj_citire
        call [printf]
        add esp, 4
        mov edi, sir
        repeta:
            push dword nr
            push dword format_citire
            call [scanf]
            add esp, 4*2
        
            mov eax, [nr]
            cmp eax, 0
            je next
            
            stosd
            
            jmp repeta
        next:
        
        cld
        mov esi, sir

        repeta2:
            
            lodsd
            cmp eax, 0
            je next2
            
            mov ebx, eax
            
            push dword ebx
            call modul
            
            push ebx
            
            push dword eax
            push dword format_afisare_fara
            call [printf]
            add esp, 4*2
            
            pop ebx
            
            push dword ebx
            push dword format_afisare_cu
            call [printf]
            add esp, 4*2
            
            jmp repeta2
            
        next2:
        
        push    dword 0
        call    [exit]
