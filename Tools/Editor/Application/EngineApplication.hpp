#pragma once

#include "Engine/Application/Application.hpp"
#include "Engine/Application/ApplicationSettings.hpp"


class EngineApplication: public nova::Application
{
public:
	EngineApplication(nova::ApplicationSettings settings, int window_handle);
};