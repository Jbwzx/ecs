#pragma once

#include "../../utils/CompileTimeAutoId.hpp"
#include "../../utils/Vector2D.hpp"
#include "../core/Component.hpp"

COUNTER_INC(ComponentAutoCounterId)
class Transform : public Component {
public:
    static constexpr ComponentId ID = COUNTER_READ(ComponentAutoCounterId) - 1;

    Vector2D m_position;
    float m_rotation;

    Transform();
};


