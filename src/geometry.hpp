
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

void closest_segment_segment(glm::vec3 sA, glm::vec3 eA, glm::vec3 sB, glm::vec3 eB, glm::vec3 *implementationResultA, glm::vec3* implementationResultB);

friend istream& operator>>(istream& input, glm::vec3 & v) {
    
}

#endif // __GEOMETRY_HPP__
