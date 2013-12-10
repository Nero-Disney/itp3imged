#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_action_ffnen_triggered();

	void on_actionBeenden_triggered();

	void on_action_ber_triggered();

	void on_actionSpeichern_unter_triggered();

	void on_actionR_ckg_ngig_triggered();

	void on_actionZur_cksetzen_triggered();

private:
	Ui::MainWindow *ui;
	//Dialogs


	void createConnections();
};

#endif // MAINWINDOW_H
