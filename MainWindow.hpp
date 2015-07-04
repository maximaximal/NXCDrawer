#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QUndoStack>
#include <NXCDrawingScreen.hpp>

class ConnectNXT;
class NXTCommunicator;

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
        void on_singleLines_clicked();

        void on_continousLine_clicked();

        void on_width_valueChanged(int arg1);

        void on_height_valueChanged(int arg1);

        void on_actionVerbindung_herstellen_triggered();

private:
        Ui::MainWindow *ui;
        QUndoStack *m_undoStack;

        NXCDrawingScreen *m_nxcDrawingScreen;
        ConnectNXT *m_connectNXT;
        NXTCommunicator *m_nxtCommunicator;
};

#endif // MAINWINDOW_HPP
