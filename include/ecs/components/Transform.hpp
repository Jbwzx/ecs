#pragma once

#include "../../utils/CompileTimeAutoId.hpp"
#include "../core/Component.hpp"

COUNTER_INC(ComponentAutoCounterId)
class Transform : public Component {
public:
    static constexpr ComponentId ID = COUNTER_READ(ComponentAutoCounterId) - 1;

    float m_x, m_y; // TODO
};


