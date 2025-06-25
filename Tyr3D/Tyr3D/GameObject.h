#pragma once
#include <vector>
#include <memory>
#include "Component.h"

namespace Tyr3D
{
	class GameObject
	{

	public:
		void Start();
		void Update(float dt);

		//add component & get component must be in header
		template<typename T>
		T* AddComponent()
		{
			std::unique_ptr<T> uP =std::make_unique<T>(this);
			T* p = uP.get();
			memberComponents.push_back(std::move(uP));
			return p;
		}

		template<typename T>
		T*GetComponent() 
		{
			const std::type_info& targetType = typeid(T);

			for (auto& component : memberComponents)
			{
				const std::type_info& componentType = typeid(*component);
				if (targetType == componentType) {
					return static_cast<T*>(component.get());
				}
			}
			return nullptr;
		}


	private:
		std::vector<std::unique_ptr<Component>>memberComponents;

	}; 
}
