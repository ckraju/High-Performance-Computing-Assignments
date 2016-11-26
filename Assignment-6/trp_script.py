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
strv="trp_serial.c"
for vap in our_range:
	subprocess.call(["gcc","-fopenmp",strv,"-w"])
	cmd = ["./a.out",str(vap)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_serial.append(output)

strv="trp_calculating.c"
for vap in our_range:
	subprocess.call(["mpicc","-fopenmp",strv,"-w"])
	cmd = ["mpiexec", "-n","2", "./a.out",str(vap)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel2.append(output)

strv="trp_calculating.c"
for vap in our_range:
	subprocess.call(["mpicc","-fopenmp",strv,"-w"])
	cmd = ["mpiexec", "-n","4", "./a.out",str(vap)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel4.append(output)
strv="trp_calculating.c"
for vap in our_range:
	subprocess.call(["mpicc","-fopenmp",strv,"-w"])
	cmd = ["mpiexec", "-n","8", "./a.out",str(vap)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel8.append(output)
strv="trp_calculating.c"
for vap in our_range:
	subprocess.call(["mpicc","-fopenmp",strv,"-w"])
	cmd = ["mpiexec", "-n","12", "./a.out",str(vap)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel12.append(output)

strv="trp_calculating.c"
for vap in our_range:
	subprocess.call(["mpicc","-fopenmp",strv,"-w"])
	cmd = ["mpiexec", "-n","16", "./a.out",str(vap)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print (output)
	time_parallel16.append(output)



print ("time_serial= ",time_serial)
print ("time_parallel2= ",time_parallel2)
print ("time_parallel4= ",time_parallel4)
print ("time_parallel8= ",time_parallel8)
print ("time_parallel12= ",time_parallel12)
print ("time_parallel16= ",time_parallel16)




