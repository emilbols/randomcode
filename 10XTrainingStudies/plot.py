import matplotlib
matplotlib.use('Agg')

infile=open('losses94XnoLept.log','r')
trainloss=[]
valloss=[]
epochs=[]
i=1
count = 1
automax=0
automin=100
for line in infile:
    count = count + 1
    #if count<137: continue
    if len(line)<1: continue
    t1=float(line.split(' ')[0])
    v1=float(line.split(' ')[1])
    trainloss.append(t1)
    valloss.append(v1)
    epochs.append(count)
    i=i+1
    if i==5:
        automax=max(t1,v1)
    automin=min(automin,v1,t1)
print count
import matplotlib.pyplot as plt
f = plt.figure()
plt.plot(epochs,trainloss,'r',label='train')
plt.plot(epochs,valloss,'b',label='val')
plt.ylabel('loss')
plt.xlabel('epochs')
plt.legend()
plt.ylim([0.5,0.8])
f.savefig('lossDeepFlavour94XnoLept.pdf')
plt.close()
