
#ifndef __GEOMETRY_HPP__
#define __GEOMETRY_HPP__

#include "math.hpp"
#include <iostream>
#include <fstream>

enum
{
    eINSIDE      = -1,
    eOVERLAPPING = 0,
    eOUTSIDE     = 1
};

glm::vec3 closest_point_plane(glm::vec3 point, glm::vec3 plane_normal, float d);

friend istream& operator>>(istream& input, glm::vec3 & v) {
    
}

#endif // __GEOMETRY_HPP__
