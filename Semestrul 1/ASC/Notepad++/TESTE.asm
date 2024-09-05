bits 32

global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    b db ~a
    a equ 5




segment code use32 class=code
    start:
        push EBP
        MOV EBP,ESP
        MOV EBP,[EBP]
        MOV EBX,[EBP]
        MOV [ESP],EBX
        
        push    dword 0
        call    [exit]
