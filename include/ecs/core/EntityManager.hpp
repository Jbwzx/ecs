#pragma once

#include <EASTL/vector.h>
#include <EASTL/hash_map.h>
#include "EntitySystemTypes.hpp"
#include "Entity.hpp"
#include "System.hpp"

class EntityManager {
    using Entities = eastl::hash_map<EntityId, Entity>;
    using Components = eastl::vector<eastl::vector<Component*>>;
    using Systems = eastl::vector<System>;

    Systems m_systems;
    Components m_allComponents;
    Entities m_entities;

public:
    EntityManager();
    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;
    EntityManager(const EntityManager&&) = delete;
    EntityManager& operator=(const EntityManager&&) = delete;
    ~EntityManager();

    void CreateSystems();
    void Update(double deltaTime);

    EntityId CreateEntity();
    void DestroyEntity(EntityId entityId);
};