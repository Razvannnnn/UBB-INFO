bits 32 
global start        
extern exit ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll ; exit is a function that ends the calling process. It is defined in msvcrt.dll
; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
; our data is declared here (the variables needed by our program)
segment data use32 class=data
	s db 'a', 'b', 'c', 'm','n' ; declararea sirului initial s
	l equ $-s ; stabilirea lungimea sirului initial l
	d times l db 0 ; rezervarea unui spatiu de dimensiune l pentru sirul destinatie d si initializarea acestuia

segment code use32 class=code
start:
	mov ecx, l ;punem lungimea in ECX pentru a putea realiza bucla loop de ecx ori
	mov esi, 0     
	jecxz Sfarsit      
	Repeta:
		mov al, [s+esi]
		mov bl, 'a'-'A' ; pentru a obtine litera mare corespunzatoare literei mici, vom scadea din codul ASCII 
                        ; al literei mici diferenta dintre 'a'-'A'
		sub al, bl             
		mov [d+esi], al    
		inc esi
	loop Repeta
	Sfarsit:;terminarea programului

	; exit(0)
	push dword 0 ; push the parameter for exit onto the stack
	call [exit] ; call exit to terminate the program