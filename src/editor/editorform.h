#pragma once

#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget {
	Q_OBJECT

public:
	explicit EditorForm(QWidget *parent = nullptr);
	~EditorForm();
	void itemSelected(const QModelIndex &index);

	// Item editing methods
	void setItemLabel(const QString &label);

private:
	Ui::EditorForm *ui;
	QStandardItemModel *itemModel;
	QStandardItem *selectedItem;
};
