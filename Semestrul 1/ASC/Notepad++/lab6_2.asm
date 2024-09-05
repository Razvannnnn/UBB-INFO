 bits 32
global start        
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
; our data is declared here (the variables needed by our program)
segment data use32 class=data

    s dw 12345, 20778, 4596
    l equ ($-s)/2
    d times l*5 db 0
    zece dw 10
    
segment code use32 class=code
    
    ; Dandu-se un sir de cuvinte sa se obtina sirul (de octeti) cifrelor in baza zece ale fiecarui cuvant din acest sir.
    ; Exemplu:
    ; daca avem sirul:
    ; sir DW 12345, 20778, 4596 
    ; obtinem rezultatul
    ; 1, 2, 3, 4, 5, 2, 0, 7, 7, 8, 4, 5, 9, 6.
    
    
    start:
    mov esi, s
    mov edi, d
    mov ecx, l
    cld
    jecxz Sfarsit
    Repeta:
        lodsw   ;AX = numarul
        mov bx, 1
        nr_cif:
            push ax 
            mov ax, bx ;ax = 1
            mov bx, 10 ;bx = 10
            mul bx ; ax = 10
            mov bx, ax ;bx= 10
            pop ax ; ax=nr
            cmp ax, bx
            jb next
            cmp bx, 10000
            je cifre
            cmp ax, bx
            ja nr_cif
        next:
        push ax
        mov ax, bx
        mov bx, 10
        mov dx, 0
        div bx
        mov bx, ax
        pop ax 
        cifre:
            push ax
            mov dx, 0
            div bx
            stosb
            mov ax, dx
            push ax
            mov ax, bx
            mov bx, 10
            mov dx, 0
            div bx
            mov bx, ax
            pop ax
            cmp bx, 0
            jne cifre
    loop Repeta
    Sfarsit:
    
    ; start:
    ; mov esi, s
    ; mov edi, d
    ; mov ecx, l
    ; cld
    ; jecxz Sfarsit
    ; Repeta:
        ; lodsw   ;AX = numarul
        
        ; cifre:
            ; mov dx, 0
            ; mov bx, 10
            ; div bx   ; DX = Ultima cifra
            ; push ax
            ; mov ax, dx
            ; stosb
            ; pop ax
            ; cmp ax, 0
            ; jne cifre    
    ; loop Repeta
    ; Sfarsit:
    
    
    push dword 0      ; push the parameter for exit onto the stack
    call [exit]       ; call exit to terminate the program
