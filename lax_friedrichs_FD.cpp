//
//  lax_friedrichs_FD.cpp
//  lax_friedrichs_FD
//
//  Created by Kevin Zhang on 12/5/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#include "lax_friedrichs_FD.hpp"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//smooth initial condition
double u_0(double x){
    double u_0 = exp(-100*pow(0.3-x,2.0));
    return u_0;
}

vector<double> lax_friedrichs_FD(int a, int b, double dx, double dt, double max_t, double c){
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
        for (int j = 1; j < u.size(); ++j){
            u[j] = 0.5*(uprev[j]+uprev[j-1])-0.5*nu*(uprev[j+1]-uprev[j-1]);
            u[0] = *uprev.end();
            *u.end() = uprev[0];
        }
        uprev = u;
    }
    
    return u;
}
