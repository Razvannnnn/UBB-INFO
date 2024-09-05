bits 32                         
segment code use32 public code
global modul

modul:
    push eax
    push edx
    
    mov ebx, 1
    repeta:
        cmp ebx, eax
        ja next1
        shl ebx, 1
        jmp repeta
    next1:
            
    sub ebx, eax
    mov eax, ebx
    
    pop edx
    pop eax
    
    ret 4
     