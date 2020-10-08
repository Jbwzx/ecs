#pragma once

#include "ecs/core/EntityManager.hpp"

class Application {
    EntityManager m_entityManager;

public:
    bool Init();
    void Update(double deltaTime);
};
