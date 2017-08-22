//
//  main.cpp
//  DynamicTimeWarp
//
//  Created by Dustin on 2017-08-22.
//  Copyright © 2017 Dustin Johnson. All rights reserved.
//

#include <iostream>
#include <vector>
#include "dtw.hpp"

int main(int argc, const char * argv[]) {
    
    std::vector<double> x = {1, 3, 4, 7, 65, 8, 90, 3, 65, 1, 23, 4, 6, 3, 7, 7, 7, 3, 23, 9};
    std::vector<double> y = {2, 4, 6, 435, 6, 1, 1, 9, 67, 12, 23, 5, 7, 8, 3, 7, 7, 4, 9, 9};
    
    DTW dist;
    dist.dtwDistance(x, y, 15);
    dist.lBKeoghLowerBound(x, y, 3);
    
}

