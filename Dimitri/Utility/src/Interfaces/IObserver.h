#pragma once
namespace Interfaces {
	template <class T>
	class  __declspec(dllexport) IObserver {
	public:
		virtual void update(const T& object) = 0;
	};
}