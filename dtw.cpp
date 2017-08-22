//
//  dtw.cpp
//  DynamicTimeWarp
//
//  Created by Dustin on 2017-08-22.
//  Copyright © 2017 Dustin Johnson. All rights reserved.
//

#include "dtw.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

DTW::DTW()
{
    
}

double DTW::dtwDistance(const std::vector<double> &x, const std::vector<double> &y, int w)
{
    using std::vector;
    
    // initialize constants
    const double inf_ = std::numeric_limits<double>::infinity();
    const int x_length_ = static_cast<int>(x.size());
    const int y_length_ = static_cast<int>(y.size());
    
    vector< vector<double> > dtw(x_length_, vector<double>(y_length_));
    double dist;
    
    // Initialize all dtw matrix elements to infnty
    for(int i = 0; i < x_length_; ++i)
    {
        dtw[i][0] = inf_;
    }
    
    for(int i = 0; i < y_length_; ++i)
    {
        dtw[0][i] = inf_;
    }
    dtw[0][0] = 0;
    
    // add locality constraint
    w = std::max(w, std::abs(x_length_ - y_length_));
    
    // Determine the optimal dtw path via dynamic programming,
    // specifically the recursive function outlined on wiki:
    // https://en.wikipedia.org/wiki/Dynamic_time_warping
    for(int i = 1; i < x_length_; ++i)
    {
        // adapt inner loop to window size
        for(int j = std::max(1, i - w); j < std::min(y_length_, i + w); ++j)
        {
            dist = std::pow(x[i] - y[j], 2);
            dtw[i][j] = dist + std::min({dtw[i - 1][j], dtw[i][j - 1], dtw[i - 1][j - 1]});
        }
    }
    
    // compute distance metric
    double dtwDist = std::sqrt(dtw[x_length_ - 1][y_length_ - 1]);
    
    std::cout << dtwDist << "\n";
    return dtwDist;
}

double DTW::lBKeoghLowerBound(const std::vector<double> &x, const std::vector<double> &y, int r)
{
    double lowerBound;
    double upperBound;
    std::vector<double> yBound;
    double lbSum = 0;
    
    for(int i = 0; i < x.size(); ++i)
    {
        for(int j = i - r; j < i + r; ++j)
        {
            if (j >= 0)
            {
                yBound.push_back(y[j]);
            }
        }
        
        lowerBound = *std::min_element(yBound.begin(), yBound.end());
        upperBound = *std::max_element(yBound.begin(), yBound.end());
        
        if (i > upperBound)
        {
            lbSum = lbSum + std::pow(x[i] - upperBound, 2);
        } else {
            lbSum = lbSum + std::pow(x[i] - lowerBound, 2);
        }
    }
    
    std::cout << std::sqrt(lbSum) << "\n";
    return std::sqrt(lbSum);
}

DTW::~DTW(void)
{
    
}