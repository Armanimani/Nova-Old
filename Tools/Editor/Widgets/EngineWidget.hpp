#pragma once

#include <QtWidgets/QtWidgets>

class EngineWidget final : public QWidget 
{
	Q_OBJECT
public:
	explicit EngineWidget(QWidget* parent);

	[[nodiscard]] int get_window_handle() const noexcept;
protected:
	QPaintEngine* paintEngine() const override;
};