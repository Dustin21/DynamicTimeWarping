//
//  dtw.hpp
//  DynamicTimeWarp
//
//  Created by Dustin on 2017-08-22.
//  Copyright © 2017 Dustin Johnson. All rights reserved.
//

#ifndef dtw_hpp
#define dtw_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class DTW
{
public:
    double dtwDistance(const std::vector<double> &x, const std::vector<double> &y, int w);
    double lBKeoghLowerBound(const std::vector<double> &x, const std::vector<double> &y, int r);
    
    DTW();
    ~DTW();
};


#endif /* dtw_hpp */
