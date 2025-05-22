#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "editor/editorform.h"

MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	setCentralWidget(new EditorForm());
}

MainWindow::~MainWindow() {
	delete ui;
}
