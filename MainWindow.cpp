#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_undoStack = new QUndoStack();

    ui->setupUi(this);

    QAction *undoAction = m_undoStack->createUndoAction(ui->menuBearbeiten);
    undoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    ui->menuBearbeiten->addAction(undoAction);

    QAction *redoAction = m_undoStack->createRedoAction(ui->menuBearbeiten);
    redoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    ui->menuBearbeiten->addAction(redoAction);

    m_nxcDrawingScreen = new NXCDrawingScreen(m_undoStack);
    ui->drawingView->setScene(m_nxcDrawingScreen);
    ui->drawingView->setMouseTracking(true);

    m_nxcDrawingScreen->setDrawingMode(NXCDrawingScreen::ContinousLine);
    m_nxcDrawingScreen->setSceneRect(QRectF(0, 0, 210, 297));
}

MainWindow::~MainWindow()
{
    delete m_undoStack;
    delete m_nxcDrawingScreen;

    delete ui;
}

void MainWindow::on_singleLines_clicked()
{
    m_nxcDrawingScreen->setDrawingMode(NXCDrawingScreen::SingleLines);
}
void MainWindow::on_continousLine_clicked()
{
    m_nxcDrawingScreen->setDrawingMode(NXCDrawingScreen::ContinousLine);
}

void MainWindow::on_width_valueChanged(int arg1)
{
    QRectF sceneRect = m_nxcDrawingScreen->sceneRect();

    sceneRect.setWidth(arg1);

    m_nxcDrawingScreen->setSceneRect(sceneRect);
}

void MainWindow::on_height_valueChanged(int arg1)
{
    QRectF sceneRect = m_nxcDrawingScreen->sceneRect();

    sceneRect.setHeight(arg1);

    m_nxcDrawingScreen->setSceneRect(sceneRect);
}
