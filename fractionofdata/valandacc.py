import matplotlib
import os
matplotlib.use('Agg')

directory = 'fullinfo'
trainloss=[]
valloss=[]
trainacc=[]
valacc=[]
epochs=[]
jets = 173540000
for filename in os.listdir(directory):
    if filename.endswith(".log"):
	infile=open(os.path.join(directory, filename))
	line = infile.readlines()[-1]
        acc = line.split('"acc": ')[-1].split(',')[0]
        loss = line.split('"loss": ')[-1].split(',')[0]
        val_acc = line.split('"val_acc": ')[-1].split(',')[0]
        val_loss = line.split('"val_loss": ')[-1].split('}')[0]
        trainacc.append(float(acc))
        valacc.append(float(val_acc))
        trainloss.append(float(loss))
        valloss.append(float(val_loss))        
	digit = (filename.split('p')[0]).split('nfo')[1]	
	percent = (filename.split('p')[1]).split('.log')[0]
	frac = digit + '.' + percent
	epochs.append(float(frac)*jets)
epochs, valloss, trainloss, valacc, trainacc = zip(*sorted(zip(epochs, valloss, trainloss,valacc,trainacc)))
import matplotlib.pyplot as plt
f = plt.figure()
plt.plot(epochs,trainloss,'r',label='train')
plt.plot(epochs,valloss,'b',label='val')
plt.ylabel('loss')
plt.xlabel('number of jets')
plt.legend()
f.savefig('lossvsdata.pdf')

b = plt.figure()
plt.plot(epochs,trainacc,'r',label='train')
plt.plot(epochs,valacc,'b',label='val')
plt.ylabel('acc')
plt.xlabel('number of jets')
plt.legend()
b.savefig('accvsdata.pdf')
plt.close()
