#!/usr/bin/env python
import subprocess
#import matplotlib.pyplot as plt

init = 1000
# Running the codes

time_serial=[]
size=[]
print "Serial Execution"
for i in range(1,6):
				
	init = init *10
	subprocess.call(["gcc","-fopenmp","q2.c","-lm","-w"])	
	cmd = ["./a.out",str(init)]
	size.append(init)
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	time_serial.append(float(output.split(' ')[1]))
	

time_parallel=[]
times_p=[]
init = 1000
threadarr = [1,2,4,8,12]

print "Parallel Execution"
for i in range(1,6):			
	init = init *10
	for j in range(0,5):
		print "Number of threads are "+str(threadarr[j])
		subprocess.call(["gcc","-fopenmp","q2_p.c","-lm","-w"])	
		cmd = ["./a.out",str(init),str(threadarr[j])]
		output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
		times_p.append(float(output.split(' ')[1]))
		if(j>3):
			time_parallel.append(float(output.split(' ')[1]))
			


	
print size
print time_serial
print time_parallel
speedup =[]
for i in range(0,5):
	speedup.append(time_serial[i]/time_parallel[i])

print speedup

overhead=[]
speedup2=[]
speedup4=[]
speedup8=[]
speedup12=[]
eff2=[]
eff4=[]
eff8=[]
eff12=[]

for j in range(0,5):
	overhead.append(time_serial[j]-times_p[j*5])
	speedup2.append(time_serial[j]/times_p[j*5 + 1])
	eff2.append(speedup2[j]/2)
	speedup4.append(time_serial[j]/times_p[j*5 + 2])
	eff4.append(speedup4[j]/4)
	speedup8.append(time_serial[j]/times_p[j*5 + 3])
	eff8.append(speedup8[j]/8)
	speedup12.append(time_serial[j]/times_p[j*5 + 4])
	eff12.append(speedup12[j]/12)

print "Overhead"
print overhead
print "Speedup of different threads"
print speedup2
print speedup4
print speedup8
print speedup12
print "Efficiency of different threads"
print eff2
print eff4
print eff8
print eff12

"""
plt.plot(speedup, size)
plt.plot()
plt.xlabel('Problem Size')
plt.ylabel('Speedup')
plt.show()
"""
