//
//  beamwarm_FD.cpp
//  beam_warming_FD
//
//  Created by Kevin Zhang on 12/5/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#include "beamwarm_FD.hpp"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//smooth initial condition
double u_0(double x){
    double u_0 = exp(-100*pow(0.3-x,2.0));
    return u_0;
}

vector<double> beam_warming_FD(int a, int b, double dx, double dt, double max_t, double c){
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
        for (int j = 2; j < u.size(); ++j){
            if (c > 0){
                u[0] = *uprev.end();
                u[1] = uprev[1] -  0.5*nu*(3*uprev[1]-4*uprev[0]+ *uprev.end()) + 0.5*nu*nu*(uprev[1]-2*uprev[0]+ *uprev.end());
                u[j] = uprev[j] - 0.5*nu*(3*uprev[j]-4*uprev[j-1]+uprev[j-2]) + 0.5*nu*nu*(uprev[j]-2*uprev[j-1]+uprev[j-2]);
                *(u.end()-1) = *(uprev.end()-1) - 0.5*nu*(3* *(uprev.end()-1)-4* *(uprev.end()-2)+ *(uprev.end()-3)) + 0.5*nu*nu*(*(uprev.end()-1)-2* *(uprev.end()-2)+ *(uprev.end()-3));
                *u.end() = uprev[0];
            }
            else{
                u[0] = *uprev.end();
                u[1] = uprev[1] + 0.5*nu*(3*uprev[1]-4*uprev[2]+uprev[3]) +0.5*nu*nu*(uprev[1]-2*uprev[2]+uprev[3]);
                u[j] = uprev[j] + 0.5*nu*(3*uprev[j]-4*uprev[j+1]+uprev[j+2]) +0.5*nu*nu*(uprev[j]-2*uprev[j+1]+uprev[j+2]);
                *(u.end()-1)  = *(uprev.end()-1) + 0.5*nu*(3* *(uprev.end()-1)-4* *uprev.end()+uprev[0]) + 0.5*nu*nu*(*(uprev.end()-1)-2* *uprev.end()+uprev[0]);
                *u.end() = uprev[0];
            }
        }
        uprev = u;
    }
    return u;
}
