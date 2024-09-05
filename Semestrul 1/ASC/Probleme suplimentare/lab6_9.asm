bits 32

global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    s dd 12345678h, 1A2C3C4Dh, 98FCDD76h, 12783A2Bh
    len equ ($-s)/4
    d times (len/4)+1 dd 0


segment code use32 class=code
    start:
        mov eax, len
        mov edx, 0
        mov ebx, 4
        div ebx
        mov ecx, eax
        mov ebx, edx
        mov esi, s
        mov edi, d
        cld
        jecxz next
        
        Repeta:
            push ecx
            mov ecx, 4
            Repeta1:
                lodsd
                shr eax, 8
                mov bl, al
                mov eax, 0
                mov eax, ebx
                ror eax, 8
                mov ebx, eax
            loop Repeta1
            
            
            pop ecx
        loop Repeta
        
        next:
            cmp ebx, 0
            je Sfarsit
            push ebx
            mov ecx, ebx
            cld
            Repeta2:
                lodsd
                shr eax, 8
                mov bl, al
                mov eax, 0
                mov eax, ebx
                ror eax, 8
                mov ebx, eax
            loop Repeta2
            pop eax
            mov ecx, 4
            sub ecx, eax
            mov eax, ebx
            Repeta3:
                ror eax, 8
            loop Repeta3
            stosd
            
        Sfarsit:
        
        push    dword 0
        call    [exit]
