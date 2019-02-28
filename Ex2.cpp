#include <TMB.hpp>

template <class Type> Type square(Type x){return x*x;}

template<class Type>
Type objective_function<Type>::operator() ()
{
  DATA_VECTOR(Predator);
  DATA_MATRIX(Consumps);
DATA_MATRIX(Preys);
DATA_INTEGER(Npts);
DATA_VECTOR(Prey1);
DATA_VECTOR(ConsumpsPrey1);
DATA_VECTOR(Prey2);
DATA_VECTOR(ConsumpsPrey2);
DATA_VECTOR(Prey3);
DATA_VECTOR(ConsumpsPrey3);
DATA_INTEGER(Model);


PARAMETER(logalpha);
PARAMETER(logalpha2);
PARAMETER(logalpha3);
PARAMETER(beta);
PARAMETER(beta2);
PARAMETER(beta3);
PARAMETER(gamma);
PARAMETER(gamma2);
PARAMETER(gamma3);
PARAMETER(lambda);
PARAMETER(lambda2);
PARAMETER(lambda3);
Type alpha=exp(logalpha);
Type alpha2=exp(logalpha2);
Type alpha3=exp(logalpha3);
vector<Type>ypred(Npts);
vector<Type>ypred2(Npts);
vector<Type>ypred3(Npts);
vector<Type> Like;
vector<Type> Like2;
vector<Type> Like3;


if (Model==1){
ypred=alpha*Predator;
ypred2=alpha2*Predator;
ypred3=alpha3*Predator;
Like=(log(ypred)-log(ConsumpsPrey1))*(log(ypred)-log(ConsumpsPrey1));
Like2=(log(ypred2)-log(ConsumpsPrey2))*(log(ypred2)-log(ConsumpsPrey2));
Like3=(log(ypred3)-log(ConsumpsPrey3))*(log(ypred3)-log(ConsumpsPrey3));
Type f1 = sum(Like);
Type f2 = sum(Like2);
Type f3 = sum(Like3);
Type obj_fun=f1+f2+f3;
return obj_fun;

ADREPORT(alpha);
ADREPORT(alpha2);
ADREPORT(alpha3);

}

if(Model==2){
ypred=(alpha*Predator)/(1+beta*Prey1);
ypred2=(alpha2*Predator)/(1+beta2*Prey2);
ypred3=(alpha3*Predator)/(1+beta3*Prey3);
Like=(log(ypred)-log(ConsumpsPrey1))*(log(ypred)-log(ConsumpsPrey1));
Like2=(log(ypred2)-log(ConsumpsPrey2))*(log(ypred2)-log(ConsumpsPrey2));
Like3=(log(ypred3)-log(ConsumpsPrey3))*(log(ypred3)-log(ConsumpsPrey3));
Type f1 = sum(Like);
Type f2 = sum(Like2);
Type f3 = sum(Like3);
Type obj_fun=f1+f2+f3;
return obj_fun;
}

if(Model==3){

ypred=(alpha*Predator*pow(Prey1,gamma-1))/(1+beta*pow(Prey1,gamma));
ypred2=(alpha2*Predator*pow(Prey2,gamma2-1))/(1+beta2*pow(Prey2,gamma2));
ypred3=(alpha3*Predator*pow(Prey3,gamma3-1))/(1+beta3*pow(Prey3,gamma3));
Like=(log(ypred)-log(ConsumpsPrey1))*(log(ypred)-log(ConsumpsPrey1));
Like2=(log(ypred2)-log(ConsumpsPrey2))*(log(ypred2)-log(ConsumpsPrey2));
Like3=(log(ypred3)-log(ConsumpsPrey3))*(log(ypred3)-log(ConsumpsPrey3));
Type f1 = sum(Like);
Type f2 = sum(Like2);
Type f3 = sum(Like3);
Type obj_fun=f1+f2+f3;
return obj_fun;
}

if (Model==4){
ypred=(alpha*Predator)/(1+beta*Prey1+lambda*Predator);
ypred2=(alpha2*Predator)/(1+beta2*Prey1+lambda2*Predator);
ypred3=(alpha3*Predator)/(1+beta3*Prey1+lambda3*Predator);
Like=(log(ypred)-log(ConsumpsPrey1))*(log(ypred)-log(ConsumpsPrey1));
Like2=(log(ypred2)-log(ConsumpsPrey2))*(log(ypred2)-log(ConsumpsPrey2));
Like3=(log(ypred3)-log(ConsumpsPrey3))*(log(ypred3)-log(ConsumpsPrey3));
Type f1 = sum(Like);
Type f2 = sum(Like2);
Type f3 = sum(Like3);
Type obj_fun=f1+f2+f3;
return obj_fun;
}
}



