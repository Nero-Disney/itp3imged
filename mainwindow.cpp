#include <QtGui>
#include <QtCore>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ueberdialog.h"
#include "imagewidget.h"
#include "filters/BilateralFilter.h"
#include "filters/Blur.h"
#include "filters/Dilation.h"
#include "filters/Erosion.h"
#include "filters/GaussianBlur.h"
#include "filters/Grayscale.h"
#include "filters/MedianBlur.h"
#include "filters/Outline.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	/*Shortcuts MenuBar*/
	/*Datei*/
	ui->actionBeenden->setShortcut(tr("CTRL+B"));
	ui->actionNeu->setShortcut(tr("CTRL+N"));
	ui->action_ffnen->setShortcut(tr("CTRL+O"));
	ui->actionSpeichern->setShortcut(tr("CTRL+S"));
	ui->actionDrucken->setShortcut(tr("CTRL+P"));
	ui->actionSpeichern_unter->setShortcut(tr("CTRL+SHIFT+S"));
	/*Bearbeiten*/
	ui->actionR_ckg_ngig->setShortcut(tr("CTRL+Z"));
	ui->actionWiederherstellen->setShortcut(tr("CTRL+Y"));
	ui->actionZur_cksetzen->setShortcut(tr("CTRL+SHIFT+Z"));
	ui->actionKopieren->setShortcut(tr("CTRL+C"));
	ui->actionEinf_gen->setShortcut(tr("CTRL+V"));
	/*Hilfe*/
	ui->actionHilfe->setShortcut(tr("CTRL+H"));
	ui->action_ber->setShortcut(tr("CTRL+A"));

	createConnections();

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::createConnections()
{
	connect(ui->actionBeenden, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::on_action_ffnen_triggered()
{
	ui->statusbar->showMessage("Datei Öffnen",2000);
	QString fileName = QFileDialog::getOpenFileName(this, tr("Bilddatei öffnen"), QDir::homePath());
	if(!fileName.isEmpty()) {
		// TODO:
		// Richtiges Widget für Tab aufrufen.
		ui->imageWidget->openImage(fileName);
	}
}

void MainWindow::on_actionBeenden_triggered()
{
	ui->statusbar->showMessage("Programm Beenden",2000);
}

void MainWindow::on_action_ber_triggered()
{
	Ueberdialog about;
	about.setModal(true);
	about.exec();
}

void MainWindow::on_actionSpeichern_unter_triggered()
{


	ui->statusbar->showMessage("Speichern unter", 2000);
	QString fileName = QFileDialog::getSaveFileName(this, tr("Bilddatei abspeichern"),
		QDir::homePath(), tr("png(*.png);;jpg(*.jpg *jpeg)"));
	QStringList splitedFile = fileName.split(".");
	QString ext;
	if(!splitedFile.isEmpty()) {
		ext = splitedFile.takeLast();
	}
	if(!fileName.isEmpty()) {
		ui->imageWidget->saveImage(fileName, ext.toLatin1());
	}
}

void MainWindow::on_actionR_ckg_ngig_triggered()
{
	ui->statusbar->showMessage("Rückgängig", 2000);
	ui->imageWidget->undo();
}

void MainWindow::on_actionZur_cksetzen_triggered()
{
	ui->statusbar->showMessage("Zurücksetzen", 2000);
	ui->imageWidget->resetImage();
}

void MainWindow::on_actionBlur_triggered()
{
	Blur blur;
	ui->imageWidget->applyFilter(blur);
}
