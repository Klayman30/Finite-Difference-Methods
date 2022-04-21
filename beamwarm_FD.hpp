//
//  beamwarm_FD.hpp
//  beam_warming_FD
//
//  Created by Kevin Zhang on 12/5/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#ifndef beamwarm_FD_hpp
#define beamwarm_FD_hpp

#include <stdio.h>
#include "beamwarm_FD.hpp"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//smooth initial condition
double u_0(double x);
vector<double> beam_warming_FD(int a, int b, double dx, double dt, double max_t, double c);
#endif /* beamwarm_FD_hpp */
