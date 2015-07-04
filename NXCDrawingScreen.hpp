#ifndef NXCDRAWINGSCREEN_HPP
#define NXCDRAWINGSCREEN_HPP

#include <QGraphicsScene>
#include <QUndoStack>

class NXCDrawingScreen : public QGraphicsScene
{
    Q_OBJECT

    public:
        enum DrawingMode
        {
            ContinousLine,
            SingleLines,

            _COUNT
        };

        NXCDrawingScreen(QUndoStack *undoStack);
        virtual ~NXCDrawingScreen();

        virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

        void setDrawingMode(DrawingMode mode);
        DrawingMode drawingMode();
    private:
        QUndoStack *m_undoStack;
        DrawingMode m_mode;

        bool m_lineActive;

        QPointF m_lastPos;

        QGraphicsLineItem *m_currentLine;
        QGraphicsEllipseItem *m_lastPosCircle;
};

#endif // NXCDRAWINGSCREEN_HPP
