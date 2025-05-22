#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QStyleFactory>
#include <QTranslator>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	QTranslator translator;
	const QStringList uiLanguages = QLocale::system().uiLanguages();
	for (const QString &locale : uiLanguages) {
		const QString baseName = "control-router_" + QLocale(locale).name();
		if (translator.load(":/i18n/" + baseName)) {
			app.installTranslator(&translator);
			break;
		}
	}

	// app.styleHints()->setColorScheme(Qt::ColorScheme::Dark);
	app.setStyle(QStyleFactory::create("Fusion"));

	// QPalette pal;
	// pal.setColor(QPalette::Window, QColor(40, 40, 40));
	// pal.setColor(QPalette::WindowText, TEXT_COLOR);
	// pal.setColor(QPalette::Disabled, QPalette::WindowText, MUTED_COLOR);
	// pal.setColor(QPalette::Base, QColor(60, 60, 60));
	// pal.setColor(QPalette::Button, QColor(30, 30, 30));
	// pal.setColor(QPalette::Light, pal.color(QPalette::Button).lighter(20));
	// pal.setColor(QPalette::Midlight, pal.color(QPalette::Button).lighter(10));
	// pal.setColor(QPalette::Dark, pal.color(QPalette::Button).darker(20));
	// pal.setColor(QPalette::Mid, pal.color(QPalette::Button).darker(10));
	// pal.setColor(QPalette::Text, TEXT_COLOR);
	// pal.setColor(QPalette::Disabled, QPalette::Text, MUTED_COLOR);
	// pal.setColor(QPalette::Highlight, QColor(80, 80, 80));
	// pal.setColor(QPalette::HighlightedText, QColor(255, 142, 51));
	// pal.setColor(QPalette::ButtonText, TEXT_COLOR);
	// pal.setColor(QPalette::Disabled, QPalette::ButtonText, MUTED_COLOR);
	// app.setPalette(pal);

	MainWindow w;
	w.show();
	return app.exec();
}
