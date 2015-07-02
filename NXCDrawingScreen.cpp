#include "NXCDrawingScreen.hpp"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QPen>
#include <AddLineStrip.hpp>
#include <QDebug>

NXCDrawingScreen::NXCDrawingScreen(QUndoStack *undoStack)
    : QGraphicsScene()
{
    m_undoStack = undoStack;
    m_lineActive = false;

    QPen pen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    m_currentLine = new QGraphicsLineItem();
    m_currentLine->setPen(pen);
    m_currentLine->setZValue(10000);
    addItem(m_currentLine);

    m_lastPosCircle = new QGraphicsEllipseItem();

    QPen pen2(Qt::red, 1, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
    m_lastPosCircle->setPen(pen2);
    addItem(m_lastPosCircle);
}

NXCDrawingScreen::~NXCDrawingScreen()
{

}

void NXCDrawingScreen::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(m_mode == ContinousLine)
        {
            if(!m_lineActive)
            {
                //If the line is not active yet, start it now.
                m_lineActive = true;
                m_currentLine->show();
            }
            else
            {
                m_currentLine->show();
                //If the line is already active, ad another segment.
                QGraphicsLineItem *line = new QGraphicsLineItem();
                line->setLine(QLineF(m_lastPos, event->scenePos()));

                QPen pen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                line->setPen(pen);

                AddLineStrip *addLineStrip = new AddLineStrip(line, this);
                m_undoStack->push(addLineStrip);
            }
            m_lastPos = event->scenePos();
            m_lastPosCircle->setRect(QRectF(m_lastPos.x() - 6, m_lastPos.y() - 6, 12, 12));
        }
        else if(m_mode == SingleLines)
        {

        }
    }
    else if(event->button() == Qt::RightButton)
    {
        m_lineActive = false;
        m_currentLine->hide();
    }
}
void NXCDrawingScreen::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_mode == ContinousLine)
    {
        if(m_lineActive)
        {
            m_currentLine->setLine(QLineF(m_lastPos, event->scenePos()));
        }
    }
    else if(m_mode == SingleLines)
    {

    }
}
void NXCDrawingScreen::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_mode == ContinousLine)
    {

    }
    else if(m_mode == SingleLines)
    {

    }
}

void NXCDrawingScreen::setDrawingMode(NXCDrawingScreen::DrawingMode mode)
{
    m_mode = mode;
}
NXCDrawingScreen::DrawingMode NXCDrawingScreen::drawingMode()
{
    return m_mode;
}

