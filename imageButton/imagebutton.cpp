#include "imagebutton.h"
#include <QPainter>
#include <QRect>
imageButton::imageButton(QPixmap normal, QPixmap pressed, QWidget *parent)
    :QAbstractButton(parent)
    ,m_normal(normal)
    ,m_pressed(pressed)
    ,m_bPressed(false)
{
    connect(this, SIGNAL(pressed()), this, SLOT(onPressed()));
    connect(this, SIGNAL(released()), this, SLOT(onReleased()));
    setAttribute(Qt::WA_NoSystemBackground);
}
void imageButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawPixmap(rect(), m_bPressed ? m_pressed : m_normal);
}
void imageButton::onPressed()
{
    m_bPressed = true;
    this->update();
}
void imageButton::onReleased()
{
    m_bPressed = false;
    this->update();
}
