#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QUndoStack>
#include <NXCDrawingScreen.hpp>

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

    private:
        Ui::MainWindow *ui;
        QUndoStack *m_undoStack;

        NXCDrawingScreen *m_nxcDrawingScreen;
};

#endif // MAINWINDOW_HPP
