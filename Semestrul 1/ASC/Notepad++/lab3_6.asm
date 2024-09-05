bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 5
    b dd 11
    c db 5
    x dq 25

; our code starts here
segment code use32 class=code
    start:
        ; x-(a*a+b)/(a+c/a); a,c-byte; b-doubleword; x-qword ; Interpretare fara semn ; rezultat 19
        
        mov al, [a]
        mov bl, [a]
        mul bl ; ax=a*a
        mov bx, 0 
        mov cx, 0
        mov bx, ax ; ebx=a*a
        mov ax, [b]
        mov dx, [b+2]
        add ax, bx ; dx:ax=a*a+b
        adc dx, cx
        push dx
        push ax
        mov ah, 0
        mov al, [c]
        mov bl, [a]
        div bl ; ax/bl=al=c/a
        add al, [a] ; al=a+c/a
        mov bh, 0
        mov bl, al ; bx=a+c/a;
        pop eax
        div bx; ax=(a*a+b)/(a+c/a)
        mov ebx, 0
        mov bx, ax
        mov ecx, 0 ; ecx:ebx=(a*a+b)/(a+c/a)
        mov eax, [x]
        mov edx, [x+4] ; edx:eax=x
        sub eax, ebx
        sbb edx, ecx ; edx:eax=x-(a*a+b)/(a+c/a)
        
        ; x-(a*a+b)/(a+c/a); a,c-byte; b-doubleword; x-qword ; Interpretare cu semn
        
        
        ; mov al, [a]
        ; mov bl, [a]
        ; imul bl ; ax=a*a
        ; mov bx, [b]
        ; mov cx, [b+2]
        ; cwd
        ; add ax, bx 
        ; adc dx, cx ; dx:ax=a*a+b
        ; push(dx)
        ; push(ax)
        ; mov al, [c]
        ; cbw
        ; mov bl, [a]
        ; idiv bl ; al=c/a si ah=c%a*a
        ; add al, [a] ; al=a+c/a
        ; cbw
        ; mov bx, ax
        ; pop(eax)
        ; idiv bx ; ax=(a*a+b)/(a+c/a)
        ; cwd
        ; cdq
        ; mov ebx, eax
        ; mov ecx, edx ; ecx:ebx=(a*a+b)/(a+c/a)
        ; mov eax, [x]
        ; mov edx, [x+4] ; edx:eax=x
        ; sub eax, ebx
        ; sbb edx, ecx ; edx:eax=x-(a*a+b)/(a+c/a)
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
