bits 32

global start        

extern exit, scanf, printf          
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class=data
    format_citire db "%d", 0
    
    a dw 0
    b dw 0
    c dd 0
    
    format_afisare db "Rezultat: %x", 0


segment code use32 class=code
    start:
        push dword a
        push dword format_citire
        call [scanf]
        add esp, 4*2
        
        push dword b
        push dword format_citire
        call [scanf]
        add esp, 4*2
        
        mov ecx, 0
        
        mov ax, [a]
        mov bx, [b]
        add ax, bx
        
        mov cx, ax
        
        mov ax, [a]
        mov bx, [b]
        sub ax, bx
        
        shl ecx, 16
        mov cx, ax
        
        mov [c], ecx
        
        push dword [c]
        push dword format_afisare
        call [printf]
        add esp, 4*2
        
        push    dword 0
        call    [exit]
