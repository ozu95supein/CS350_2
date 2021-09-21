#include "common.hpp"
#include "geometry.hpp"
#include <fstream>

constexpr float c_test_epsilon = 1e-3f;

TEST(geometry, closest_point_plane)
{
    std::fstream f(WORKDIR "test/in_geometry/closest_point_plane.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3 point;
        vec3 plane_point;
        vec3 plane_normal;
        vec3 file_result{};

        // Read
        f >> point;
        f >> plane_point;
        f >> plane_normal;
        f >> file_result;

        // Test
        auto implementation_result = closest_point_plane(point, plane_normal, glm::dot(plane_point, plane_normal));
        ASSERT_NEAR(file_result, implementation_result, c_test_epsilon) << "TEST: " << i << "\n"
                                                                        << point << std::endl
                                                                        << plane_point << std::endl
                                                                        << plane_normal << std::endl
                                                                        << std::fixed << std::setprecision(16) << implementation_result << std::defaultfloat << std::setprecision(6) << std::endl;
    }
}

TEST(geometry, closest_segment_segment)
{
    std::fstream f(WORKDIR "test/in_geometry/closest_segment_segment.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3 sA, eA;
        vec3 sB, eB;
        vec3 implementationResultA, implementationResultB;
        vec3 fileResultA, fileResultB;

        // Read
        f >> sA >> eA;
        f >> sB >> eB;
        f >> fileResultA >> fileResultB;

        // Test
        closest_segment_segment(sA, eA, sB, eB, &implementationResultA, &implementationResultB);
        ASSERT_NEAR(fileResultA, implementationResultA, c_test_epsilon) << "TEST: " << i << "\n"
                                                                        << sA << std::endl
                                                                        << eA << std::endl
                                                                        << sB << std::endl
                                                                        << eB << std::endl;
        ASSERT_NEAR(fileResultB, implementationResultB, c_test_epsilon) << "TEST: " << i << "\n"
                                                                        << sA << std::endl
                                                                        << eA << std::endl
                                                                        << sB << std::endl
                                                                        << eB << std::endl;
    }
}

TEST(geometry, in_point_aabb)
{
    std::fstream f(WORKDIR "test/in_geometry/in_point_aabb.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3 point{};
        vec3 min, max;
        bool file_result{};

        // Read
        f >> point;
        f >> min >> max;
        f >> std::boolalpha >> file_result;

        // Test
        auto implementation_result = overlap_point_aabb(point, min, max);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << point << std::endl
                                                      << min << ", " << max << std::endl
                                                      << std::boolalpha << implementation_result << std::endl;
    }
}

TEST(geometry, in_point_sphere)
{
    std::fstream f(WORKDIR "test/in_geometry/in_point_sphere.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  point{};
        vec3  c{};
        float r{};
        bool  file_result{};

        // Read
        f >> point;
        f >> c >> r;
        f >> std::boolalpha >> file_result;

        // Test
        auto implementation_result = overlap_point_sphere(point, c, r);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << point << std::endl
                                                      << c << ", " << r << std::endl
                                                      << std::boolalpha << implementation_result << std::endl;
    }
}

TEST(geometry, in_plane_point)
{
    std::fstream f(WORKDIR "test/in_geometry/in_plane_point.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  plane_position, plane_normal;
        float plane_thickness = 0.0f;
        vec3  point{};
        int   file_result{};

        // Read
        f >> point;
        f >> plane_position >> plane_normal;
        f >> plane_thickness;
        f >> file_result;

        // Test
        auto implementation_result = classify_plane_point(plane_normal, glm::dot(plane_position, plane_normal), point);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << point << std::endl
                                                      << plane_position << ", " << plane_normal << std::endl
                                                      << plane_thickness << std::endl
                                                      << implementation_result << std::endl;
    }
}

TEST(geometry, in_plane_triangle)
{
    std::fstream f(WORKDIR "test/in_geometry/in_plane_triangle.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  plane_position, plane_normal;
        float plane_thickness = 0.0f;
        vec3  A, B, C;
        int   file_result{};

        // Read
        f >> plane_position >> plane_normal;
        f >> plane_thickness;
        f >> A >> B >> C;
        f >> file_result;

        // Test
        auto implementation_result = classify_plane_triangle(plane_normal, glm::dot(plane_position, plane_normal), A, B, C);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << plane_position << ", " << plane_normal << std::endl
                                                      << plane_thickness << std::endl
                                                      << A << ", " << B << ", " << C << std::endl
                                                      << implementation_result << std::endl;
    }
}

TEST(geometry, in_plane_aabb)
{
    std::fstream f(WORKDIR "test/in_geometry/in_plane_aabb.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3 plane_position, plane_normal;
        vec3 min, max;
        int  file_result{};

        // Read
        f >> plane_position >> plane_normal;
        f >> min >> max;
        f >> file_result;

        // Test
        auto implementation_result = classify_plane_aabb(plane_normal, glm::dot(plane_normal, plane_position), min, max);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << plane_position << ", " << plane_normal << std::endl
                                                      << min << ", " << max << std::endl
                                                      << implementation_result << std::endl;
    }
}

TEST(geometry, in_plane_sphere)
{
    std::fstream f(WORKDIR "test/in_geometry/in_plane_sphere.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  plane_position, plane_normal;
        vec3  sph_c;
        float sph_r;
        int   file_result{};

        // Read
        f >> plane_position >> plane_normal;
        f >> sph_c >> sph_r;
        f >> file_result;

        // Test
        auto implementation_result = classify_plane_sphere(plane_normal, glm::dot(plane_normal, plane_position), sph_c, sph_r);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << plane_position << ", " << plane_normal << std::endl
                                                      << sph_c << ", " << sph_r << std::endl
                                                      << implementation_result << std::endl;
    }
}

TEST(geometry, in_aabb_aabb)
{
    std::fstream f(WORKDIR "test/in_geometry/in_aabb_aabb.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3 minA, maxA;
        vec3 minB, maxB;
        bool file_result = true;

        // Read
        f >> minA >> maxA;
        f >> minB >> maxB;
        f >> std::boolalpha >> file_result;

        // Test
        auto implementation_result = overlap_aabb_aabb(minA, maxA, minB, maxB);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << minA << ", " << maxA << std::endl
                                                      << minB << ", " << maxB << std::endl
                                                      << std::boolalpha << implementation_result << std::endl;
    }
}

TEST(geometry, in_sphere_sphere)
{
    std::fstream f(WORKDIR "test/in_geometry/in_sphere_sphere.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  sph1_c, sph2_c;
        float sph1_r, sph2_r;
        bool  file_result = true;

        // Read
        f >> sph1_c >> sph1_r;
        f >> sph2_c >> sph2_r;
        f >> std::boolalpha >> file_result;

        // Test
        auto implementation_result = overlap_sphere_sphere(sph1_c, sph1_r, sph2_c, sph2_r);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << sph1_c << ", " << sph1_r << std::endl
                                                      << sph2_c << ", " << sph2_r << std::endl
                                                      << std::boolalpha << implementation_result << std::endl;
    }
}

TEST(geometry, in_ray_plane)
{
    std::fstream f(WORKDIR "test/in_geometry/in_ray_plane.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  ray_s, ray_d;
        vec3  plane_position, plane_normal;
        float file_result{};

        // Read
        f >> ray_s >> ray_d;
        f >> plane_position >> plane_normal;
        f >> file_result;

        // Test
        auto implementation_result = intersection_time_ray_plane(ray_s, ray_d, plane_normal, glm::dot(plane_normal, plane_position));
        ASSERT_NEAR(file_result, implementation_result, c_test_epsilon) << "TEST: " << i << "\n"
                                                                        << ray_s << ", " << ray_d << std::endl
                                                                        << plane_position << ", " << plane_normal << std::endl
                                                                        << std::fixed << std::setprecision(16) << implementation_result << std::defaultfloat << std::setprecision(6) << std::endl;
    }
}

TEST(geometry, in_ray_aabb)
{
    std::fstream f(WORKDIR "test/in_geometry/in_ray_aabb.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  ray_s, ray_d;
        vec3  min, max;
        float file_result{};

        // Read
        f >> ray_s >> ray_d;
        f >> min >> max;
        f >> file_result;

        // Test
        auto implementation_result = intersection_time_ray_aabb(ray_s, ray_d, min, max);
        ASSERT_NEAR(file_result, implementation_result, c_test_epsilon) << "TEST: " << i << "\n"
                                                                        << ray_s << ", " << ray_d << std::endl
                                                                        << min << ", " << max << std::endl
                                                                        << std::fixed << std::setprecision(16) << implementation_result << std::defaultfloat << std::setprecision(6) << std::endl;
    }
}

TEST(geometry, in_ray_sphere)
{
    std::fstream f(WORKDIR "test/in_geometry/in_ray_sphere.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  ray_s, ray_d;
        vec3  sph_c;
        float sph_r;
        float file_result{};

        // Read
        f >> ray_s >> ray_d;
        f >> sph_c >> sph_r;
        f >> file_result;

        // Test
        auto implementation_result = intersection_time_ray_sphere(ray_s, ray_d, sph_c, sph_r);
        ASSERT_NEAR(file_result, implementation_result, c_test_epsilon) << "TEST: " << i << "\n"
                                                                        << ray_s << ", " << ray_d << std::endl
                                                                        << sph_c << ", " << sph_r << std::endl
                                                                        << std::fixed << std::setprecision(16) << implementation_result << std::defaultfloat << std::setprecision(6) << std::endl;
    }
}

TEST(geometry, in_ray_triangle)
{
    std::fstream f(WORKDIR "test/in_geometry/in_ray_triangle.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  ray_s, ray_d;
        vec3  A, B, C;
        float file_result{};

        // Read
        f >> ray_s >> ray_d;
        f >> A >> B >> C;
        f >> file_result;

        // Test
        auto implementation_result = intersection_time_ray_triangle(ray_s, ray_d, A, B, C);
        ASSERT_NEAR(file_result, implementation_result, c_test_epsilon) << "TEST: " << i << "\n"
                                                                        << ray_s << ", " << ray_d << std::endl
                                                                        << A << ", " << B << ", " << C << std::endl
                                                                        << std::fixed << std::setprecision(16) << implementation_result << std::defaultfloat << std::setprecision(6) << std::endl;
    }
}

TEST(geometry, in_frustum_sphere)
{
    std::fstream f(WORKDIR "test/in_geometry/in_frustum_sphere.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  frustum_plane_n[6];
        vec3  frustum_plane_pt[6];
        float frustum_plane_d[6];
        vec3  sphere_p;
        float sphere_r;
        int   file_result{};

        // Read
        for (int p = 0; p < 6; ++p) {
            f >> frustum_plane_pt[p] >> frustum_plane_n[p];
            frustum_plane_d[p] = glm::dot(frustum_plane_pt[p], frustum_plane_n[p]);
        }
        f >> sphere_p >> sphere_r;
        f >> file_result;

        // Test
        auto implementation_result = classify_frustum_sphere_naive(frustum_plane_n, frustum_plane_d, sphere_p, sphere_r);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << sphere_p << ", " << sphere_r << std::endl
                                                      << implementation_result << std::endl;
    }
}

TEST(geometry, in_frustum_aabb)
{
    std::fstream f(WORKDIR "test/in_geometry/in_frustum_aabb.txt");
    ASSERT_TRUE(f.is_open()) << "Could not open file";

    int cases = 0;
    f >> cases;
    for (int i = 0; i < cases; ++i) {
        // Data
        vec3  frustum_plane_n[6];
        vec3  frustum_plane_pt[6];
        float frustum_plane_d[6];
        vec3  min, max;
        int   file_result{};

        // Read
        for (int p = 0; p < 6; ++p) {
            f >> frustum_plane_pt[p] >> frustum_plane_n[p];
            frustum_plane_d[p] = glm::dot(frustum_plane_pt[p], frustum_plane_n[p]);
        }
        f >> min >> max;
        f >> file_result;

        // Test
        auto implementation_result = classify_frustum_aabb_naive(frustum_plane_n, frustum_plane_d, min, max);
        ASSERT_EQ(file_result, implementation_result) << "TEST: " << i << "\n"
                                                      << min << " " << max << std::endl
                                                      << implementation_result << std::endl;
    }
}