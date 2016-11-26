#!/usr/bin/env python
import subprocess
import sys
#import matplotlib.pyplot as plt



# Running the codes
time_serial=[]
time_parallel2=[]
time_parallel4=[]
time_parallel8=[]
time_parallel12=[]
time_parallel16=[]



our_range=[100000,1000000,10000000,100000000,1000000000,10000000000]
#our_range=[1000000];


strv="trp_open.c"
for vap in our_range:
	subprocess.call(["gcc","-fopenmp",strv,"-w"])
	cmd = ["./a.out",str(vap),str(2)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel2.append(output)

strv="trp_open.c"
for vap in our_range:
	subprocess.call(["gcc","-fopenmp",strv,"-w"])
	cmd = ["./a.out",str(vap),str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel4.append(output)
strv="trp_open.c"
for vap in our_range:
	subprocess.call(["gcc","-fopenmp",strv,"-w"])
	cmd = ["./a.out",str(vap),str(8)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel8.append(output)
strv="trp_open.c"
for vap in our_range:
	subprocess.call(["gcc","-fopenmp",strv,"-w"])
	cmd = ["./a.out",str(vap),str(12)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel12.append(output)

strv="trp_open.c"
for vap in our_range:
	subprocess.call(["gcc","-fopenmp",strv,"-w"])
	cmd = ["./a.out",str(vap),str(16)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel16.append(output)



print ("time_serial= ",time_serial)
print ("time_parallel2= ",time_parallel2)
print ("time_parallel4= ",time_parallel4)
print ("time_parallel8= ",time_parallel8)
print ("time_parallel12= ",time_parallel12)
print ("time_parallel16= ",time_parallel16)




