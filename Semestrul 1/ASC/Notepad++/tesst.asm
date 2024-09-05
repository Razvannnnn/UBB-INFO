bits 32

global start        

extern exit, scanf, printf     
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll    


segment data use32 class=data
    
    mesaj_afisare db "Sirul de caractere: ", 0
    sir_caractere db 50
    sir_numere db 50
    input db "%s", 0


segment code use32 class=code
    start:
        push dword mesaj_afisare
        call [printf]
        add esp, 4
        
        push dword sir_caractere
        push dword input
        call [scanf]
        add esp, 4*2
        
        lea edi, [sir_caractere]
        lea esi, [sir_numere]
        xor ecx, ecx 
        
        push dword sir_numere
        call [printf]
        add esp, 4
        
        
        push    dword 0
        call    [exit]
