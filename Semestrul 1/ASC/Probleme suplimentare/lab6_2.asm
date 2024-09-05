bits 32

global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    s dw 1432h, 8675h, 0ADBCh
    l equ ($-s)/2
    d times l dd 0
    vect times 4 db 0
    ok db 0
    i resb 1

segment code use32 class=code
    start:
        mov esi, s
        mov edi, d
        mov ecx, l
        cld
        Repeta:
            cmp ecx, 0
            jz Sfarsit
            mov eax, 0
            lodsw
            push ecx
            push esi
            mov ecx, 4
            cld
            mov esi, vect
            Vector:
                mov bx, ax
                and bx, 0Fh
                mov [esi], bl
                shr ax, 4
                inc esi
            loop Vector
            pop esi
            pop ecx
            
            push ecx
            push esi
            mov byte[ok], 1
            sortare:
                cmp byte[ok], 0
                jz afara
                
                mov byte[ok], 0
                mov esi, vect
                mov ecx, 3
                Sir:
                    mov al, [esi]
                    cmp al, [esi+1]
                    jg swap
                    jmp altfel
                    
                    swap:
                        mov bl, [esi+1]
                        mov [esi], bl
                        mov [esi+1], al
                        mov byte[ok], 1
                    altfel:
                        inc esi
                loop Sir
            jmp sortare
            
            afara:
            pop esi
            pop ecx
            
            push ecx
            push esi
            mov ecx, 4
            mov ax, 0
            mov bx, 0
            mov esi, vect
            numar_nou:
                shl bx, 4
                lodsb
                or bx, ax
            loop numar_nou
            
            mov ax, bx
            pop ecx
            pop esi
            
            
            mov bx, ax
            mov eax, 0
            
            push ecx
            mov ecx, 4
            mov byte[i], 0
            
            Repeta1:
                mov edx, 0
                mov dx, bx
                and dx, 0Fh
                
                push ecx
                mov cl, [i]
                shl edx, cl
                pop ecx
                or eax, edx
                
                shr bx, 4
                add byte[i], 8
            loop Repeta1
            
            stosd
            pop ecx
        jmp Repeta
        
        Sfarsit:
        push    dword 0
        call    [exit]
