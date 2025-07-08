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
			//makes unique pointer to this game object
			std::unique_ptr<T> uPtr =std::make_unique<T>(this);
			//sets template class pointer to point to game object
			T* ptr = uPtr.get();
			//adds component to  vector of components attached to this game object
			memberComponents.push_back(std::move(uPtr));
			return ptr;
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
