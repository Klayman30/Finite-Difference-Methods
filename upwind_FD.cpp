//
//  upwind_FD.cpp
//  upwind_FD
//
//  Created by Kevin Zhang on 12/4/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#include "upwind_FD.hpp"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//smooth initial condition
double u_0(double x){
    double u_0 = exp(-100*pow(0.3-x,2.0));
    return u_0;
}

vector<double> upwind_FD(int a, int b, double dx, double dt,int max_t, double c){
    double nu = (c*dt)/dx;
    
    vector<double> space;
    for (int j=0; j<=(b-a)/dx; ++j){
        space.push_back(a+j*dx);
        space.push_back(b);
    }
    
    vector<double> time;
    for (int j=0; j<=max_t/dt; ++j){
        time.push_back(j*dt);
    }
    
    vector<double> uprev;
    for (int j=0; j<space.size(); ++j){
        uprev.push_back(u_0(space[j]));
    }
    
    vector<double> u;
    for (auto i = uprev.begin(); i != uprev.end(); ++i){
        u.push_back(0* *i);
    }
    for (int n = 0; n <= time.size(); ++n){
        for (int j = 1; j < u.size() ; ++j){
            if(c>0){
                u[j] = uprev[j] - nu*(uprev[j]-uprev[j-1]);
                *u.end() = *uprev.end()-nu*(*uprev.end() - *(uprev.end()-1));
            }
            else{
                u[j] = uprev[j]-nu*(uprev[j+1]-uprev[j]);
                *u.end() = *uprev.end() - nu*( *uprev.begin()-*uprev.end());
            }
            *u.begin() = *uprev.end();
        }
        uprev = u;
    }
    return u;
}

