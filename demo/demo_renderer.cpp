#include "window.hpp"
#include "camera.hpp"
#include "debug_system.hpp"
#include "imgui.hpp"
#include "math.hpp"
#include "opengl.hpp"
#include <fstream>
#include <sstream>
#include <chrono>

namespace {
    struct
    {
        int debug_case = 0;
    } settings;
}

// HELPERS
// void draw_point(vec3 const& p, vec4 const& color)
// {
// }

// void draw_segment(segment const& s, vec4 const& color)
// {
// }

// void draw_aabb(aabb const& bv, vec4 const& color)
// {
// }

// void draw_sphere(sphere const& bv, vec4 const& color)
// {
// }

// void draw_triangle(triangle const& t, vec4 const& color)
// {
// }

// void draw_plane(vec3 const& p, vec3 const& n, float s, vec4 const& color)
// {
// }

// void draw_frustum(frustum const& f, vec4 const& color)
// {
// }

void update_camera(float dt)
{
}

int main()
{
    //auto& window = g_window;
    //imgui_init(window.handle());
    //while (window.update())
    {
        // dt
        static auto prev = std::chrono::high_resolution_clock::now();
        auto        now  = std::chrono::high_resolution_clock::now();
        auto        dt   = std::chrono::duration<float>(now - prev).count();
        prev             = now;
        update_camera(dt);

        // Render
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        { // ImGUI
            imgui_new_frame();

            imgui_end_frame();
        }
    }
    imgui_destroy();
    return 0;
}