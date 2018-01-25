#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H
#include <QAbstractButton>
#include <QPixmap>

class imageButton : public QAbstractButton
{
    Q_OBJECT
public:
    imageButton(QPixmap normal, QPixmap pressed, QWidget *parent = 0);

protected slots:
    void onPressed();
    void onReleased();

protected:
    void paintEvent(QPaintEvent *e);
    QPixmap m_normal;
    QPixmap m_pressed;
    bool m_bPressed;
};

#endif // IMAGEBUTTON_H
