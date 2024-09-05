bits 32                         
segment code use32 public code
global modul

modul:
    push eax
    push edx
    
    mov edx, 1
    mov eax, 0
    sub eax, ebx
    sbb edx, 0
    mov ebx, eax
    
    pop edx
    pop eax
    ret 4
     