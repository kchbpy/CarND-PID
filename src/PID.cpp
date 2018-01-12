#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kd = Kd;
    PID::Kp = Kp;
    PID::Ki = Ki;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    isInited = true;
    window = 20;
}

void PID::UpdateError(double cte) {
    //Should initialize the PID first
    if(!isInited){throw "Not Init";}
    //if is the first time set pre_cte with the current cte
    if(index==0){
        pre_cte = cte;
    }
    if(index < window){
        ctes.push_back(cte);
    }
    else{
        ctes.erase(ctes.begin());
        ctes.push_back(cte);
    }
    for(unsigned int i=0; i<ctes.size(); i++)
    {
        i_error = i_error + ctes[i];    //caculate the integration
    }
    //i_error = i_error+cte;
    p_error = cte;
    d_error = cte-pre_cte;
    pre_cte = cte;  //Refresh the pre_cte
    
    index+=1;
    
}

double PID::TotalError() {
    //should initializ the PID first
    if(isInited){
        return -Kd*d_error - Ki*i_error - Kp*p_error;
    }
    else{
        throw "Not Init";
    }
}

