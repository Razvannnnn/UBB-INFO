bits 32

global start        

extern exit, scanf, printf               
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class=data
    mesaj1 db "A=", 0
    mesaj2 db "B=", 0
    
    format_citire db "%d", 0
    
    afisare db "<%d> * <%d> = <%d>", 0
    
    a dw 0
    b dw 0
    
    result dd 0

segment code use32 class=code
    start:
        push dword mesaj1
        call [printf]
        add esp, 4
        
        push dword a
        push dword format_citire
        call [scanf]
        add esp, 4*2
        
        push dword mesaj2
        call [printf]
        add esp, 4
        
        push dword b
        push dword format_citire
        call [scanf]
        add esp, 4*2
        
        mov ax, [a]
        mov bx, [b]
        mul bx
        
        mov [result], eax
        
        mov bx, [a]
        mov cx, [b]
        
        push dword [result]
        push dword [b]
        push dword [a]
        push dword afisare
        call [printf]
        add esp, 4*4
        
        push    dword 0
        call    [exit]
