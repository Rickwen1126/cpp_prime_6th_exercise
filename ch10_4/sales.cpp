
//  sales.cpp --for sol-9-04.cpp

#include "sales.h"
#include <iostream>

namespace SALES
{
    Sales::Sales(const double ar[], int n) {       
        double max, min, total = .0;
        for (int i = 0; i < QUARTERS; i++)
        {
            if (n > i)
                this->sales[i] = ar[i];
            else
                this->sales[i] = .0;
            total +=this->sales[i];
        }
        max = min = this->sales[0];
        for (int i = 0; i < n && i < QUARTERS; i++)
        {
            if (max < this->sales[i])
                max = this->sales[i];
            if (min > this->sales[i])
                min = this->sales[i];
        }
        this->max = max;
        this->min = min;
        this->average = (n < QUARTERS) ? total / n : total / QUARTERS;   
    }
    void Sales::setSales()
    {
        double max, min, total = .0;
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cout << "Enter sales #" << i + 1 << ": ";
            std::cin >> this->sales[i];
            total += this->sales[i];
        }
        max = min = this->sales[0];
        for (int i = 0; i < QUARTERS; i++)
        {
            if (max < this->sales[i])
                max = this->sales[i];
            if (min > this->sales[i])
                min = this->sales[i];
        }
        this->average = total / QUARTERS;
        this->max = max;
        this->min = min;
    }
    void Sales::showSales() const
    {
        for (int i = 0; i < QUARTERS; i++)
            std::cout << "sales #" << i + 1 << ": " << this->sales[i] << std::endl;
        std::cout << "average: " << this->average << "\n"
                  << "max:     " << this->max << "\n"
                  << "min:     " << this->min << std::endl;
    }
} // namespace SALES