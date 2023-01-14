//
// Created by Alexander Winter on 2023-01-07.
//

#ifndef LD52_CLIENT_MATHUTIL_H
#define LD52_CLIENT_MATHUTIL_H

#include "SFML/System/Vector2.hpp"

namespace MathUtil
{
    inline sf::Vector2f toFloat(sf::Vector2i intVec) {
        return sf::Vector2f { static_cast<float>(intVec.x), static_cast<float>(intVec.y) };
    }
    inline sf::Vector2f toFloat(sf::Vector2u intVec) {
        return sf::Vector2f { static_cast<float>(intVec.x), static_cast<float>(intVec.y) };
    }
    
    inline constexpr const float pow2(float x) {
        return x * x;
    }

    inline std::string decToHex(int n)
    {
        // ans string to store hexadecimal number
        std::string ans = "";

        while (n != 0) {
            // remainder variable to store remainder
            int rem = 0;

            // ch variable to store each character
            char ch;
            // storing remainder in rem variable.
            rem = n % 16;

            // check if temp < 10
            if (rem < 10) {
                ch = rem + 48;
            }
            else {
                ch = rem + 55;
            }

            // updating the ans string with the character variable
            ans += std::tolower(ch);
            n = n / 16;
        }

        // reversing the ans string to get the final result
        int i = 0, j = ans.size() - 1;
        while(i <= j)
        {
            std::swap(ans[i], ans[j]);
            i++;
            j--;
        }
        return ans.length() == 3 ? "0" + ans : ans;
    }

}

#endif //LD52_CLIENT_MATHUTIL_H
