#include <iostream>
#include <random>
#include <algorithm>
#include <memory>
#include <numbers>
#include <numeric>

#include <curves.h>

constexpr auto pi = std::numbers::pi_v<float>;
constexpr auto test_curves_count = 100;


int main()
{
    // random init
    std::random_device rd;
    std::default_random_engine dre(rd());

    // container of [test_curves_count] random curves (2)
    std::vector<std::shared_ptr<ICurve>> curves(test_curves_count);
    std::ranges::generate(curves, [&dre]() -> std::shared_ptr<ICurve> {
        std::uniform_int_distribution<int> type_dist(0, 3);
        std::uniform_real_distribution<float> rad_dist(0.f, 1000.f);
        std::uniform_real_distribution<float> step_dist(-100.f, 100.f);

        switch(type_dist(dre))
        {
            case 0: 
                return std::make_shared<Circle>(rad_dist(dre));
            case 1: 
                return std::make_shared<Ellipse>(rad_dist(dre), rad_dist(dre));
            case 2:
            default:
                return std::make_shared<Helix>(rad_dist(dre), step_dist(dre));
        }
    });

    // printing container's content (3)
    std::ranges::for_each(curves, [](auto&& curve_ptr) {
        std::cout << "--== " << curve_ptr->ToString() << " ==--\n";
        
        auto p = curve_ptr->Point(pi/4.f);
        std::cout << "\tCoords at t = pi/4:\n" <<
            "\tX =\t" << p.x << '\n' <<
            "\tY =\t" << p.y << '\n' <<
            "\tZ =\t" << p.z << '\n';

        auto d = curve_ptr->Derivative(pi/4.f);
        std::cout << "\tPartial Derivatives at t = pi/4:\n" <<
            "\tX =\t" << d.x << '\n' <<
            "\tY =\t" << d.y << '\n' <<
            "\tZ =\t" << d.z << "\n\n";
    });

    // filter only circles to second container (4)
    std::vector<std::shared_ptr<Circle>> circles;
    for(auto&& curve_ptr : curves)
    {
        if(auto p = std::dynamic_pointer_cast<Circle>(curve_ptr))
        {
            circles.emplace_back(p);
        }
    }

    std::cout << "[!] Filtered " << circles.size() << " circles\n";

    // sort circles by radius (5)
    std::ranges::sort(circles, [](auto&& lhs, auto&& rhs) {
        return lhs->Radius() < rhs->Radius();
    });

    std::cout << "[!] Sorted by radius:\n";
    std::ranges::for_each(circles, [](auto&& circle_ptr) {
        std::cout << circle_ptr->Radius() << '\n';
    });

    // calculate sum of circle radiuses (6)
    auto sum = std::accumulate(circles.cbegin(), circles.cend(), 0.f, [](float sum, auto&& circle_ptr) {
        return sum + circle_ptr->Radius();
    });

    std::cout << "[!] Sum of radiuses: " << sum << "\n";

    return 0;
}