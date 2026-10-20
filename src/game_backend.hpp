#pragma once
#include "mobile_menu.hpp"
#include <functional>
#include <memory>
#include <vector>
#include <cstdint>
namespace vt::ios {
struct EspItem {float x=0,y=0,headY=0,distance=0;std::string label;};
class GameBackend {
    struct State;
    std::unique_ptr<State> state;
public:
    using Resolver=std::function<void*(const char*)>;
    explicit GameBackend(Resolver resolver);
    ~GameBackend();
    void tick(Model&,double time);
    void toggle(Model&,int feature);
    void stop(Model&);
    std::string diagnostic() const;
    const std::vector<EspItem>& esp() const;
};
}
