#include "Application/Application.hpp"

extern "C"
	{__declspec(dllexport) void start_editor_application()
	{
		editor::binding::Application app;
		app.run();
	}
}