Data1 Segment
  Vb		db	10011b
  String	db	'–€док Ц new'
  Vw     	dw	4567d
  Vw2     	dw	4567
  vw3		dw	6476
  Vd		dd	0d7856fdah
Data1 ends

val equ 30
val2 equ 32

Code Segment
 label1:
  Cli
  IF val eq 30
  Inc	ax
  ELSE
  Dec 	byte ptr[si+2]
  ENDIF
  Cmp 	Ax, ds:word ptr[si+2]
  Jna 	Label2
  And	byte ptr[si+2],ax
  Inc 	BH
  Add 	ax, 5
  Mov 	dx, val  
  cmp 	ax, word ptr[si+2]
  Jna 	label1
  Label2:


Code ends
end