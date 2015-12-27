data          SEGMENT  
 val1         dd       11225599
 val2         dq       33.14
 val3         dd       33.14
data          ENDS

code          SEGMENT    
               Fcos
               Fadd val1[eax]
               Fadd  st(0),st(1)
               Fcomp st(0)
               Fadd dword ptr[ebx]

code          ENDS
end