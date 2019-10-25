#pragma once

#include <QtWidgets/QtWidgets>

class EngineWidget final : public QWidget 
{
public:
	explicit EngineWidget(QWidget* parent);
	
	int get_window_handle() const noexcept;
protected:
	QPaintEngine* paintEngine() const override;
};