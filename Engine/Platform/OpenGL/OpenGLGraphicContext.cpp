#include "OpenGLGraphicContext.hpp"

#include <GL/glew.h>
#include <windows.h>

namespace nova
{
	// TODO: Refactor this code for window client
	
	HDC g_handle_device_context{};
	
	OpenGLGraphicContext::OpenGLGraphicContext(Int64 window_handle): GraphicContext(window_handle)
	{
	}

	void OpenGLGraphicContext::initialize()
	{
		g_handle_device_context = GetDC((HWND)(get_window_handle()));

		PIXELFORMATDESCRIPTOR pixel_format_descriptor =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			32,
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,
			8,
			0,
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		const auto pixel_format = ChoosePixelFormat(g_handle_device_context, &pixel_format_descriptor);

		if (!SetPixelFormat(g_handle_device_context, pixel_format, &pixel_format_descriptor))
		{
			LOG_ENGINE_ERROR("Unable to set the pixel format");
		}
		
		const auto handle_rendering_context = wglCreateContext(g_handle_device_context);

		if (!handle_rendering_context)
		{
			LOG_ENGINE_ERROR("Failed to create OpenGL rendering context");
		}

		if (!wglMakeCurrent(g_handle_device_context, handle_rendering_context))
		{
			LOG_ENGINE_ERROR("Failed to set OpenGL rendering context");
		}

		if(glewInit() != GLEW_OK)
		{
			LOG_ENGINE_ERROR("Failed to initialzie GLEW");
		}
	}

	void OpenGLGraphicContext::present()
	{
		SwapBuffers(g_handle_device_context);
	}

	GraphicAPI OpenGLGraphicContext::get_graphic_api()
	{
		return GraphicAPI::OpenGL;
	}
}
