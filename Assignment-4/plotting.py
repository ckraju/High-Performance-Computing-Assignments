import subprocess
import os

x=9

f="pr1serial"
print f +" implemetation"
print "serially "


for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "



f="q1"
print f +" implemetation"
print "2 "


for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(2)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "



print "3 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(3)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "


print "4 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "

print "8 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "

print "12 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "

print "16 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "



f="pr2serial"
print f +" implemetation"
print "serially "


for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "

f="pr2"
print f +" implemetation"
print "2 "


for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(2)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "



print "3 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(3)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "


print "4 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "

print "8 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "

print "12 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "

print "16 "
for i in range(4,x):
	n = str(1.6*(   10**(i+1)))
	subprocess.call(["gcc","-fopenmp",f+".c"])	
	cmd = ["./a.out",n,str(4)]
	output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
	print output
print " "
