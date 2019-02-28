setwd("C:/Users/w10007346/Documents/Fish 559/Day2")
data1<-read.table("Ex2.dat", skip=4, header=T)
Prey1<-data1$Prey1
Predator1<-data1$Predator
Preys<-as.matrix(data1[,c(2:4)])
Consump<-as.matrix(data1[,c(5:7)])
data<-list(Prey1=Prey1, Prey2=data1$Prey2, Prey3=data1$Prey3,
           ConsumpsPrey1=data1$Consump_of_prey1,ConsumpsPrey2=data1$Consump_of_prey2, ConsumpsPrey3=data1$Consumpof_prey3, Predator=data1$Predator, 
           Preys=Preys, Consumps=Consump, Model=3, Npts=100, Nprey=3)



parameters<-list(logalpha=1, logalpha2=1, logalpha3=.1, beta=.1, beta2=.1, beta3=.1, gamma=1, gamma2=1, gamma3=1,
                 lambda=1, lambda2=1, lambda3=1)

require(TMB)
compile("Ex2.cpp")
dyn.load(dynlib("Ex2"))

################################################################################
data<-list(Prey1=Prey1, Prey2=data1$Prey2, Prey3=data1$Prey3,
           ConsumpsPrey1=data1$Consump_of_prey1,ConsumpsPrey2=data1$Consump_of_prey2, ConsumpsPrey3=data1$Consumpof_prey3, Predator=data1$Predator, 
           Preys=Preys, Consumps=Consump, Model=1, Npts=100, Nprey=3)
map<-list(beta=factor(NA), beta2=factor(NA), beta3=factor(NA),gamma=factor(NA), gamma2=factor(NA), gamma3=factor(NA),
        lambda=factor(NA), lambda2=factor(NA), lambda3=factor(NA))

model <- MakeADFun(data, parameters, map=map,DLL="Ex2",silent=T)
fit <- nlminb(model$par, model$fn, model$gr)

best <- model$env$last.par.best
rep <- sdreport(model)

print(best)
print(rep)


######## Model 2

data<-list(Prey1=Prey1, Prey2=data1$Prey2, Prey3=data1$Prey3,
           ConsumpsPrey1=data1$Consump_of_prey1,ConsumpsPrey2=data1$Consump_of_prey2, ConsumpsPrey3=data1$Consumpof_prey3, Predator=data1$Predator, 
           Preys=Preys, Consumps=Consump, Model=2, Npts=100, Nprey=3)
map<-list(gamma=factor(NA), gamma2=factor(NA), gamma3=factor(NA),
          lambda=factor(NA), lambda2=factor(NA), lambda3=factor(NA))


model2 <- MakeADFun(data, parameters, map=map,DLL="Ex2",silent=T)
fit2 <- nlminb(model2$par, model2$fn, model2$gr)

best2 <- model2$env$last.par.best
rep2 <- sdreport(model2)

print(best2)
print(rep2)

###### Model 3 ########################
data<-list(Prey1=Prey1, Prey2=data1$Prey2, Prey3=data1$Prey3,
           ConsumpsPrey1=data1$Consump_of_prey1,ConsumpsPrey2=data1$Consump_of_prey2, ConsumpsPrey3=data1$Consumpof_prey3, Predator=data1$Predator, 
           Preys=Preys, Consumps=Consump, Model=3, Npts=100, Nprey=3)

map<-list(lambda=factor(NA), lambda2=factor(NA), lambda3=factor(NA))

model3 <- MakeADFun(data, parameters,map=map,DLL="Ex2",silent=T)
fit3 <- nlminb(model3$par, model3$fn, model3$gr)

best3 <- model3$env$last.par.best
rep3 <- sdreport(model3)

print(best3)
print(rep3)

######## Model 4 ###########################
data<-list(Prey1=Prey1, Prey2=data1$Prey2, Prey3=data1$Prey3,
           ConsumpsPrey1=data1$Consump_of_prey1,ConsumpsPrey2=data1$Consump_of_prey2, ConsumpsPrey3=data1$Consumpof_prey3, Predator=data1$Predator, 
           Preys=Preys, Consumps=Consump, Model=4, Npts=100, Nprey=3)

map<-list(gamma=factor(NA), gamma2=factor(NA), gamma3=factor(NA))

model4 <- MakeADFun(data, parameters, map=map,DLL="Ex2",silent=T)
fit4 <- nlminb(model4$par, model4$fn, model4$gr)

best4 <- model4$env$last.par.best
rep4 <- sdreport(model4)

print(best4)
print(rep4)

