n=input("Enter the number of lines: ")
print("Enter the fie: ")
i=0
a=""
string =raw_input("")
a=a+string
while(i+1<n):
	string =raw_input("")
	a = a+" "+string
	i=i+1
i=0
error=0
list=a.split(" ")
opcode =['LDA','STA']
opvalue=[ 000, 111 ]
symtab = []
symvalue = []
symflag=[]
in1=[]
in2=[]
in3=[]
in4=[]
j=1
line=0
locctr=0

if(list[1]=='START'):
	locctr=int(list[j+1])
	in1.append(locctr)
	in2.append('START')
	in3.append(locctr)
	in4.append('')
	line=3
while(list[line+1]!='END'):
	if(list[line]!='-'):
		if(list[line] in symtab):
			j=symtab.index(list[line])
			symflag[j]=1
		else:
			symtab.append(list[line])
			symvalue.append(locctr)
			symflag.append(0)
	in1.append(locctr)
	if(list[line+1] in opcode):
		locctr=locctr+3
		#verified opcode
	elif(list[line+1] == 'WORD'):
		locctr=locctr+3
	elif(list[line+1] == 'RESW'):
		operand = int(list[line+2])
		locctr=locctr + 3*operand	
	elif(list[line+1] == 'RESB'):
		operand = int(list[line+2])
		locctr=locctr + operand	
	elif(list[line+1] == 'BYTE'):
		#pinne typam
		numbyte = list[line+2].split(",")
		operand = len(numbyte)
		locctr=locctr+operand
	else:
		print ("Invalid opcode " + list[line+1])
		error = 1
	if(error != 1):
		in2.append(list[line])
		in3.append(list[line+1])
		in4.append(list[line+2])
	line=line+3
in1.append(locctr)
in2.append(list[line])
in3.append(list[line+1])
in4.append(list[line+2])
#print list
if(error !=1):
	n=len(in1)
	for i in range(n):
		print  in1[i] ,in2[i] ,in3[i] ,in4[i]  
	symlength=len(symtab)
	for i in range(symlength):
		print   symtab[i],symvalue[i],symflag[i] 