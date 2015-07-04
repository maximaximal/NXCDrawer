#include "AddLineStrip.hpp"

AddLineStrip::AddLineStrip(QGraphicsItem *item, QGraphicsScene *scene)
    : QUndoCommand()
{
    m_graphicsItem = item;
    m_graphicsScene = scene;
}

AddLineStrip::~AddLineStrip()
{

}

void AddLineStrip::undo()
{
    m_graphicsScene->removeItem(m_graphicsItem);
}
void AddLineStrip::redo()
{
    m_graphicsScene->addItem(m_graphicsItem);
}

