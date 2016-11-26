import subprocess
import os




f="q1"
print f +"serial of first problem  implemetation  512*512"
print " "

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm',">>"," out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output



f="q1"
print f +"serial of first problem  implemetation 1024*1024"
print " "


subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q1"
print f +"serial of first problem  implemetation 2000*2000"
print " "

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q1"
print f +"serial of first problem  implemetation 3000*3000"
print " "

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output



f="q1_p1"
print f +"parallel of first problem  implemetation 512*512"
print " "

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q1_p1"
print f +"parallel of first problem  implemetation 1024*1024"
print " "


subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output



f="q1_p1"
print f +"serial of first problem  implemetation 2000*2000"
print " "


subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q1_p1"
print f +"serial of first problem  implemetation 3000*3000"
print " "


subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output



"""

problem 2
"""



f="q2"
print f +"serial of second problem  implemetation 512*512"
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 512*512"
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 512*512"
print " 5"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 512*512"
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 512*512"
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 512*512"
print " 5"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l500.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output










f="q2"
print f +"serial of second problem  implemetation 1024*1024" 
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 1024*1024"
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 1024*1024"
print " 5"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 1024*1024"
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 1024*1024"
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 1024*1024"
print "5 "

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l1000.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output










f="q2"
print f +"serial of second problem  implemetation 2000*2000" 
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 2000*2000" 
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 2000*2000" 
print " 5"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 2000*2000" 
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 2000*2000" 
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 2000*2000" 
print "5 "

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l2000.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output










f="q2"
print f +"serial of second problem  implemetation 3000*3000"  
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 3000*3000"
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


f="q2"
print f +"serial of second problem  implemetation 3000*3000"
print " 5"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 3000*3000"
print " 3"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm','3',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 3000*3000"
print " 4"

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm','4',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output

f="q2_p1"
print f +"parallel of second problem  implemetation 3000*3000"
print "5 "

subprocess.call(["gcc","-fopenmp",f+".c","-lm"])	
cmd = ["./a.out",'l3000.ppm','5',">>","out.txt"]
output = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]
print output


