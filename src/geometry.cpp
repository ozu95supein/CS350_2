#include "geometry.hpp"
#include <math.h>
glm::vec3 closest_point_plane(glm::vec3 point, glm::vec3 plane_normal, float d)
{
	float t = (glm::dot(plane_normal, point) - d) / glm::dot(plane_normal, plane_normal);
	return (point - t * plane_normal);
{;
}