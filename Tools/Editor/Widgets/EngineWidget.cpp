#include "EngineWidget.hpp"

EngineWidget::EngineWidget(QWidget* parent): QWidget(parent)
{
}

int EngineWidget::get_window_handle() const noexcept
{
	return winId();
}

QPaintEngine* EngineWidget::paintEngine() const
{
	// TODO: This need to be overwritten if context is DirectX otherwise it need to be here for OpenGL
	return nullptr;
}
