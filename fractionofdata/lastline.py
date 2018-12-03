import matplotlib
import os
matplotlib.use('Agg')

directory = 'dataloss'
trainloss=[]
valloss=[]
epochs=[]
jets = 173540000
#jets = 2
for filename in os.listdir(directory):
    if filename.endswith(".log"):
	infile=open(os.path.join(directory, filename))
	last = infile.readlines()[-1]
	t1=float(last.split(' ')[0])
	v1=float(last.split(' ')[1])
	trainloss.append(t1)
	valloss.append(v1)
	digit = (filename.split('p')[0]).split('oss')[1]	
	percent = (filename.split('p')[1]).split('.log')[0]
	frac = digit + '.' + percent
	epochs.append(float(frac)*jets)
epochs, valloss, trainloss = zip(*sorted(zip(epochs, valloss, trainloss)))
import matplotlib.pyplot as plt
f = plt.figure()
plt.plot(epochs,trainloss,'r',label='train')
plt.plot(epochs,valloss,'b',label='val')
plt.ylabel('loss')
plt.xlabel('number of jets')
plt.legend()
plt.ylim([0.3,0.5])
f.savefig('test.pdf')
plt.close()
