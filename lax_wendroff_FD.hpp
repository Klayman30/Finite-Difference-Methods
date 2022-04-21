//
//  lax_wendroff_FD.hpp
//  lax_wendroff_FD
//
//  Created by Kevin Zhang on 12/5/18.
//  Copyright © 2018 Kevin Zhang. All rights reserved.
//

#ifndef lax_wendroff_FD_hpp
#define lax_wendroff_FD_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double u_0(double x);
vector<double> lax_wendroff_FD(int a, int b, double dx, double dt, double max_t, double c);

#endif /* lax_wendroff_FD_hpp */
