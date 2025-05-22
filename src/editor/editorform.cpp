#include "editorform.h"
#include "ui_editorform.h"

EditorForm::EditorForm(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::EditorForm) {
	ui->setupUi(this);

	// Set up the editor fields
	connect(ui->nameEdit, &QLineEdit::textChanged, this, &EditorForm::setItemLabel);

	// Set up the item list
	itemModel = new QStandardItemModel();

	QStandardItem *item = new QStandardItem();
	item->setText("Test");
	itemModel->appendRow(item);

	item = new QStandardItem();
	item->setText("Test 2");
	itemModel->appendRow(item);

	ui->listView->setModel(itemModel);
	connect(ui->listView, &QAbstractItemView::clicked, this, &EditorForm::itemSelected);
}

EditorForm::~EditorForm() {
	delete ui;
}

void EditorForm::itemSelected(const QModelIndex &index) {
	selectedItem = itemModel->itemFromIndex(index);
	ui->nameEdit->setText(selectedItem->text());
}

void EditorForm::setItemLabel(const QString &label) {
	selectedItem->setText(label);
}
