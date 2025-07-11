#pragma once


namespace Tyr3D
{
	class Core {
	public:
		// must be public
		static void CreateWindow(int width, int height, const char* name);
		void Run();
		float CalcDelta();
	private:
		
	
	};
}