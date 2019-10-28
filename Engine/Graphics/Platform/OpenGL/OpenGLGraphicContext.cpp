#include "Engine/Graphics/Platform/OpenGL/OpenGLGraphicContext.hpp"

#include <GL/glew.h>
#include <windows.h>

namespace nova::graphics
{
	OpenGLGraphicContext::OpenGLGraphicContext(const GraphicSettings& settings): GraphicContext(settings)
	{
		m_window_handle = reinterpret_cast <HWND>(settings.window_handle);
	}

	OpenGLGraphicContext::~OpenGLGraphicContext()
	{
		if (!wglGetCurrentContext())
		{
			wglMakeCurrent(m_device_context_handle, nullptr);
		}

		if (!m_rendering_context_handle)
		{
			wglDeleteContext(m_rendering_context_handle);
		}
	}

	void OpenGLGraphicContext::initialize()
	{
		m_device_context_handle = GetDC(m_window_handle);

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

		const auto pixel_format = ChoosePixelFormat(m_device_context_handle, &pixel_format_descriptor);

		if (!SetPixelFormat(m_device_context_handle, pixel_format, &pixel_format_descriptor))
		{
			LOG_ENGINE_ERROR("Unable to set the pixel format");
		}
		
		m_rendering_context_handle = wglCreateContext(m_device_context_handle);

		if (!m_rendering_context_handle)
		{
			LOG_ENGINE_ERROR("Failed to create OpenGL rendering context");
		}

		if (!wglMakeCurrent(m_device_context_handle, m_rendering_context_handle))
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
		SwapBuffers(m_device_context_handle);
	}

	GraphicAPI OpenGLGraphicContext::get_graphic_api() const noexcept
	{
		return GraphicAPI::OpenGL;
	}

	std::vector<GraphicCardInformation> OpenGLGraphicContext::get_adapter_information()
	{
		LOG_ENGINE_ERROR("Unable to get adaptor information for OpenGL, method is not implemented yet");
		return {};
	}
}
