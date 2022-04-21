//
//  upwind_FD.hpp
//  upwind_FD
//
//  Created by Kevin Zhang on 12/4/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#ifndef upwind_FD_hpp
#define upwind_FD_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double u_0(double x);
vector<double> upwind_FD(int a, int b, double dx, double dt,int max_t, double c);


#endif /* upwind_FD_hpp */
