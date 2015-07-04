#ifndef ADDLINESTRIP_HPP
#define ADDLINESTRIP_HPP

#include <QUndoCommand>
#include <QGraphicsItem>
#include <QGraphicsScene>

class AddLineStrip : public QUndoCommand
{
    public:
        AddLineStrip(QGraphicsItem *item, QGraphicsScene *scene);
        virtual ~AddLineStrip();

        virtual void undo();
        virtual void redo();
    private:
        QGraphicsItem *m_graphicsItem;
        QGraphicsScene *m_graphicsScene;
};

#endif // ADDLINESTRIP_HPP
