.386
data          SEGMENT  
 val1         dd       11225599
 val2         dq       3.14
 val3         dd       1.
data          ENDS

assume cs:code, ds:data
code          SEGMENT

               Fcos
               Fadd  val1 [eax]
	        	Fadd ss:dword ptr[ebx]
               Fadd  st(0),st(1)
               Fcomp st(0)

code          ENDS
end