#KNearestNeighbor from scratch

import numpy as np
from sklearn import cross_validation
from sklearn import datasets


def find_eucladian(xtrain,xtest):
    a = np.array([xtrain])
    b = np.array([xtest])
    return (((a-b)**2).sum())

def knn_define(xtrain,ytrain,xtest,k):
    distances = []
    for i in range(xtrain.shape[0]):
        d = find_eucladian(xtrain[i],xtest)
        distances.append(d)
        
    a = distances
    a.sort()
    
    print(distances[:k])
    print(a[:k])
    ind = []
    for i in range(k):
        t=a[i]
        print(t)
        print(distances.index(t))
        print(i)
        ind.append(distances.index(t))
        #print(a[i])#har bar 1,2,3,4 hi kyun jaa rha hai us ytest mein?
       
    
    
    a =[]
    for i in ind:
        a.append(ytrain[i])
    return a
dataset = datasets.load_breast_cancer()
xtrain,xtest,ytrain,ytest = cross_validation.train_test_split(dataset.data,dataset.target)

ypred = knn_define(xtrain,ytrain,xtest[65],5)

