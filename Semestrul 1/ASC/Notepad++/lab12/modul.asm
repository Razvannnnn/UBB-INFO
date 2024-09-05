bits 32

global _modul

extern _printf      

segment data use32 class=data
    format_citire db "%x", 0
    
    format_afisare_cu dd "Cu semn: -%d ", 10, 13, 0
    format_afisare_fara dd "Fara semn: %d ", 10, 13, 0
    
    nr dd 0
    max equ 50
    sir times max+1 dd 0

segment code use32 class=code
    
    
    _modul:
        ;9. Se cere sa se citeasca de la tastatura un sir de numere, date in baza 16 (se citeste de la tastatura un sir de caractere si in memorie trebuie stocat un sir de numere). Sa se afiseze valoarea zecimala a nr atat ca numere fara semn cat si ca numere cu semn.
        
        push ebp
        mov ebp, esp
        
        mov eax, [ebp+8]

        cmp eax, 0
        je next2
        
        mov ebx, 1
        repeta:
            cmp ebx, eax
            ja next1
            shl ebx, 1
            jmp repeta
        next1:
            
        sub ebx, eax
            
        push ebx
            
        push dword eax
        push dword format_afisare_fara
        call _printf
        add esp, 4*2
            
        pop ebx
            
        push dword ebx
        push dword format_afisare_cu
        call _printf
        add esp, 4*2
            
        next2:
        
        mov esp, ebp
        pop ebp
        
        ret
