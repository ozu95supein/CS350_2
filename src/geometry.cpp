#include "geometry.hpp"
#include <math.h>
const float Epsilon = 0.0001f;

glm::vec3 closest_point_plane(glm::vec3 point, glm::vec3 plane_normal, float d)
{
	float t = (glm::dot(plane_normal, point) - d) / glm::dot(plane_normal, plane_normal);
	return (point - t * plane_normal);
}
void closest_segment_segment(glm::vec3 sA, glm::vec3 eA, glm::vec3 sB, glm::vec3 eB, glm::vec3 * implementationResultA, glm::vec3 * implementationResultB)
{
	float s;	//parameter for A segment
	float t;	//parameter for B segment
	glm::vec3 dA = eA - sA;
	glm::vec3 dB = eB - sB;
	glm::vec3 r = sA - sB;
	float a = glm::dot(dA, dA); //squared length of da
	float e = glm::dot(dB, dB); //squared length of dB
	float f = glm::dot(dB, r);

	//check if either or both segments are basically points
	if (a<=Epsilon && e <= Epsilon)
	{
		s = t = 0.0f;
		*implementationResultA = sA;
		*implementationResultB = sB;
		return;
	}
	//check is first segment is a point
	if (a <= Epsilon)
	{
		s = 0.0f;
		t = f / e;
		t = glm::clamp(t, 0.0f, 1.0f);
	}
	else
	{
		float c = glm::dot(dA, r);
		//check if second segment is a point
		if (e <= Epsilon)
		{
			t = 0.0f;
			s = glm::clamp(-c / a, 0.0f, 1.0f);
		}
		//normal case
		else
		{
			float b = glm::dot(dA, dB);
			float denominator = (a * e) - (b * b);
			if (denominator != 0.0f)
			{
				s = glm::clamp(((b*f) - (c*e)) / denominator, 0.0f, 1.0f);
			}
			else
			{
				s = 0.0f;
			}
			t = (b * s + f) / e;
			//if t is between 0 and 1 we are good, if not we need to recompute
			if (t < 0.0f)
			{
				t = 0.0f;
				s = glm::clamp(-c/a, 0.0f, 1.0f);
			}
			else if (t < 1.0f)
			{
				t = 1.0f;
				s = glm::clamp((b - c) / a, 0.0f, 1.0f);
			}	
		}
	}
	*implementationResultA = sA + dA * s;
	*implementationResultB = sB + dB * s;
	return;
}