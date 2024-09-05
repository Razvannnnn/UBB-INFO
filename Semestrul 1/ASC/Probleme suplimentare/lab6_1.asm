bits 32

global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    s dd 127F5678h, 0ABCDABCDh
    l equ ($-s)/4
    d times l dd 0

segment code use32 class=code
    start:
        mov esi, s
        mov edi, d
        mov ecx, l
        cld
        jecxz final
        Repeta:
            lodsd
            cmp eax, 0
            jl next
            
            mov bx, 0
            mov dx, 0
            add bl, al
            adc bh, 0
            shr eax, 8
            add dl, al
            adc dh, 0
            shr eax, 8
            add bl, al
            adc bh, 0
            shr eax, 8
            add dl, al
            adc dh, 0
            mov ax, dx
            shl eax, 16
            mov ax, bx
            jmp urm
            
            next:
                mov bx, 0
                mov dx, 0
                add bl, al
                sbb bh, 0
                shr eax, 8
                add dl, al
                sbb dh, 0
                shr eax, 8
                add bl, al
                sbb bh, 0
                shr eax, 8
                add dl, al
                sbb dh, 0
                mov ax, dx
                shl eax, 16
                mov ax, bx
            urm:
            stosd
        loop Repeta
        
        
        
        
        final:
        
        push    dword 0
        call    [exit]
