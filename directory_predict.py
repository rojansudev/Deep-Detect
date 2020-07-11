#from timeit import default_timer as timer
#import timeit
import pefile
import os
import sys
import cPickle
from logistic_sgd import predict,LogisticRegression
from DBN import  DBN
import theano
import numpy
import theano.tensor as T
import six.moves.cPickle as pickle


#from sklearn import preprocessing

#start = timeit.default_timer()
numpy.set_printoptions(threshold=numpy.nan)

class Multiple_Predictor:
        
        def __init__(self):
                self.feature_names=[]
                self.feature_names.append("Magic");
                self.feature_names.append("MajorLinkerVersion");
                self.feature_names.append("MinorLinkerVersion");
                self.feature_names.append("SizeOfCode");
                self.feature_names.append("SizeOfInitializedData");
                self.feature_names.append("SizeOfUninitializedData");
                self.feature_names.append("AddressOfEntryPoint");
                self.feature_names.append("BaseOfCode");
                self.feature_names.append("ImageBase");
                self.feature_names.append("SectionAlignment");
                self.feature_names.append("FileAlignment");
                self.feature_names.append("MajorOperatingSystemVersion");
                self.feature_names.append("MinorOperatingSystemVersion");
                self.feature_names.append("MajorImageVersion");
                self.feature_names.append("MinorImageVersion");
                self.feature_names.append("MajorSubsystemVersion");
                self.feature_names.append("MinorSubsystemVersion");
                self.feature_names.append("Reserved1");
                self.feature_names.append("SizeOfImage");
                self.feature_names.append("SizeOfHeaders");
                self.feature_names.append("CheckSum");
                self.feature_names.append("Subsystem");
                self.feature_names.append("DllCharacteristics");
                self.feature_names.append("SizeOfStackReserve");
                self.feature_names.append("SizeOfStackCommit");
                self.feature_names.append("SizeOfHeapReserve");
                self.feature_names.append("SizeOfHeapCommit");
                self.feature_names.append("LoaderFlags");
                self.feature_names.append("NumberOfRvaAndSizes")

                self.report=open("report.txt",'w+')
                
                #test_file_path=raw_input("Enter file path")

                self.select_feat_index=cPickle.load(open('selected_features.p','rb'))

                self.path_virus=sys.argv[1]
                
                self.dbn = pickle.load(open('151515trained_DBN_model.pkl'))            
                self.classifier=self.dbn.logLayer    

                self.cnt=0
                self.unsupport_cnt=0
                for root, directories, filenames in os.walk(self.path_virus):
                        for filename in filenames:
                                virus=os.path.join(root,filename)
                                try:
                                        pe=pefile.PE(virus)
                                        self.cnt=self.cnt+1

                                except:
                                       self.unsupport_cnt=self.unsupport_cnt+1
                                       continue

                                
                                
#pe=pefile.PE(test_file_path)
        def predict(self):     
                j=0

                feat=[]

                feat_vec=numpy.zeros([self.cnt,21])
                for root, directories, filenames in os.walk(self.path_virus):
                        for filename in filenames:
                                try:       
                                        virus=os.path.join(root,filename) 
                                        pe=pefile.PE(virus)
                                     
                                    
                                        for i in range(0,21):
	                                        val=getattr(pe.OPTIONAL_HEADER,self.feature_names[self.select_feat_index[i]]) 
	                                        feat.append(val)
	                                        
	                                feat_vec[j,:]=feat
	                                #print(final_feat_virus)
	                                j=j+1
	                                del feat[:]                
	                                
                                except:
                                        continue	                        
                #print(feat_vec)	        
	
                mi=numpy.array([  1.00000000e+00,   1.28000000e+02,   1.28000000e+02,
                         1.00000000e+00,   0.00000000e+00,   0.00000000e+00,
                         1.00000000e+00,   0.00000000e+00,   0.00000000e+00,
                         0.00000000e+00,   2.67000000e+02,   0.00000000e+00,
                         0.00000000e+00,   5.12000000e+02,   0.00000000e+00,
                         0.00000000e+00,   0.00000000e+00,   0.00000000e+00,
                         0.00000000e+00,   4.09600000e+03,   0.00000000e+00])




                ma=numpy.array([  1.60000000e+01,   4.09600000e+03,   8.19200000e+03,
                         1.00000000e+01,   6.44245094e+09,   1.00000000e+01,
                         1.87000000e+02,   3.49050499e+09,   1.01846528e+08,
                         4.19444628e+09,   5.23000000e+02,   5.04960000e+04,
                         2.51658240e+08,   2.74944000e+05,   2.22126592e+08,
                         2.56000000e+02,   6.90000000e+01,   1.00253696e+08,
                         2.13150000e+04,   3.35544320e+07,   1.39459700e+06])

                for i in range(0,21):
                        if(mi[i]==ma[i]):
                                feat_vec[:,i]=0.0
                        else:
                                feat_vec[:,i]=(feat_vec[:,i]-mi[i])/(ma[i]-mi[i])        


                #min_max_scaler = preprocessing.MinMaxScaler()

                #feat_vec[:,0:21]=min_max_scaler.fit_transform(feat_vec[:,0:21])

                #print(feat_vec)

                #final_feat_virus=numpy.genfromtxt('FINAL_DATASET_FEATURE.csv', delimiter=',')

                means=numpy.array([  8.36163582e-02,   1.47967945e-01,   5.26860862e-01,
                         4.50009540e-01,   1.60621025e-01,   4.97357375e-01,
                         4.66421700e-02,   4.19539575e-03,   4.25460790e-03,
                         6.18079023e-03,   2.35260446e-01,   5.58766459e-01,
                         6.59444218e-03,   2.64416390e-03,   2.87599082e-03,
                         3.23061260e-03,   6.29153082e-02,   3.67476138e-04,
                         9.08667623e-04,   3.19912127e-02,   2.28881862e-04])


                for i in range(0,21):
                        feat_vec[:,i]=feat_vec[:,i] > means[i]

                #print(feat_vec)

                



                
                predict_model = theano.function(
                        inputs=[self.dbn.x],
                        outputs=self.classifier.y_pred
                        )
                        
                        
                        
                self.predicted_value = predict_model(feat_vec)
                #print("PREDICTIONS  VIRUS-1   NORMAL-0")
                #print(predicted_value)
                fcount=0
                label=["safe","infected"]
                for root, directories, filenames in os.walk(self.path_virus):
                        for filename in filenames:
                          
                                virus=os.path.join(root,filename)
                                try:
                                        pe=pefile.PE(virus)

                                        #print "file %s is %s" % (virus,label[self.predicted_value[fcount]])
                                        self.report.write("file %s is %s\n" % (virus,label[self.predicted_value[fcount]]))
                                        fcount=fcount+1            

                                except:
                                        #print "file %s is not of supported format(.exe)" %(virus)
                                        self.report.write("file %s is not of supported format(.exe)\n" %(virus))
                                        continue
                        
                        
                self.count=0
                for i in self.predicted_value:
                        if i==1:
                                self.count=self.count +1 
                      
                print "Scanned files:  %d" %(self.cnt)
                print "Viruses Found: %d" %(self.count)             
                print "Unsupported files: %d" %(self.unsupport_cnt)    
                                       
                '''
                count=0.0

                for i in range(cnt):
                        if(predicted_value[i]==1):
                                count=count+1 

                print("CORRECT PREDICTIONS %d" % count)

                cnt=float(cnt)
                accuracy=(count/cnt)*100
                '''
                #end = timeit.default_timer()

                #print("ACCURACY %f" %accuracy)
                #print("time elasped %f m" % ((end-start)/60.))
                #((end-start)/60.)
                
pred=Multiple_Predictor()
pred.predict()                   
                
