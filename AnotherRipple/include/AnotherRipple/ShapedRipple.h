#ifndef SHAPEDRIPPLE_H
#define SHAPEDRIPPLE_H


#include "AnotherRippleBase.h"
#include <QtQml/qqmlregistration.h>

namespace AnotherRipple {
class ShapedRipple : public AnotherRippleBase
{
    Q_OBJECT
    QML_ELEMENT
public:
    ShapedRipple(QQuickItem *parent = 0);
    void paint(QPainter *painter) override;


private:
    const double mAlfaRatio = 128;
    double alfa_calc(double &radius) const;

};
}
#endif // SHAPEDRIPPLE_H
