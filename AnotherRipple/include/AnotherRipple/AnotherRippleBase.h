#ifndef ANOTHERRIPPLEBASE_H
#define ANOTHERRIPPLEBASE_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPen>
#include <QPainter>
#include <QPair>
#include <tuple>
#include <QPainterPath>
#include <QVectorIterator>
#include <QtQml/qqmlregistration.h>

#include "framehandler.h"

namespace AnotherRipple {
class AnotherRippleBase : public QQuickPaintedItem
{
    Q_PROPERTY(QColor color READ getCircleColor WRITE setCircleColor NOTIFY colorChanged)
    Q_PROPERTY(bool acceptEvent READ getAcceptEvent WRITE setAcceptEvent NOTIFY acceptEventChanged)
    Q_PROPERTY(int clipRadius READ getClipRadius WRITE setClipRadius)
    Q_PROPERTY(int xClipRadius READ getXClipRadius WRITE setXClipRadius)
    Q_PROPERTY(int yClipRadius READ getYClipRadius WRITE setYClipRadius)
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("AnotherRippleBase is a base class")
public:
    AnotherRippleBase(QQuickItem *parent = 0);
    void mousePressEvent(QMouseEvent *event) override;

    Q_INVOKABLE void pressed(qreal x, qreal y);

    FrameHandler *frameHandler;

    QColor getCircleColor() const;
    virtual void setCircleColor(const QColor &color);

    bool getAcceptEvent();
    void setAcceptEvent(bool accept);

    void setClipRadius(unsigned int newClipRadius);
    unsigned int getClipRadius() const { return clipRadius; }
    void setXClipRadius(unsigned int newXClipRadius);
    unsigned int getXClipRadius() const { return xClipRadius; }
    void setYClipRadius(unsigned int newYClipRadius);
    unsigned int getYClipRadius() const { return yClipRadius; }

signals:
    void stop();
    void colorChanged();
    void acceptEventChanged();

public slots:
    void rePaint();
    void endPaint();

protected:
    unsigned int clipRadius=0,xClipRadius=0,yClipRadius=0;
    QVector<std::tuple<qreal,qreal,unsigned int>> startPoses;
    qreal devide2(qreal, int);
    qreal multipl2(int);
    QColor circleColor="#20000000";
    bool acceptEvent=false;
    bool frameConnected=false;

    void addFrameHandler();
    void removeFrameHandler();
};
}
#endif // ANOTHERRIPPLEBASE_H
