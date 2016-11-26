import subprocess
import os

x=input("power of 10 or 2 based on problem no")



f="serial_p1_v2"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(10**(i-1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output

f="parallel_p1_v1"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(10**(i-1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output


f="parallel_p1_v2"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(10**(i-1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output



f="serial_p2_v1"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(10**(i-1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output


f="parallel_p2_v1"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(10**(i-1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output



f="parallel_p2_v2"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(10**(i-1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output


f="serial_p3_v1"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(2**(i+1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output



f="parallel_p3_v1"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(2**(i+1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output


f="parallel_p3_v2"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(2**(i+1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output

f="parallel_p3_v3"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(2**(i+1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output

f="parallel_p3_v4"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(2**(i+1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output


f="parallel_p3_v5"
print f +"  implemetation"
print " "

for i in range(3,x):
	n = str(2**(i+1))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,">>",f]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output


