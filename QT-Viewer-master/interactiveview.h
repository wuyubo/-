#ifndef INTERACTIVE_VIEW_H
#define INTERACTIVE_VIEW_H

#include <QGraphicsView>

class QWheelEvent;
class QKeyEvent;

class InteractiveView : public QGraphicsView
{
    Q_OBJECT
public:
     InteractiveView(QWidget *parent = 0);

    // ??????
    void setTranslateSpeed(qreal speed);
    qreal translateSpeed() const;

    // ?????????
    void setZoomDelta(qreal delta);
    qreal zoomDelta() const;

protected:
    // ??/??/??/????????????????????/????????????????/????????
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    // ???
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    // ???/???
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

public Q_SLOTS:
    void zoomIn();  // ???
    void zoomOut();  // ???
    void zoom(float scaleFactor); // ???? - scaleFactor??????????????
    void translateF(QPointF delta);  // ???

private:
    Qt::MouseButton m_translateButton;  // ?????
    qreal m_translateSpeed;  // ??????
    qreal m_zoomDelta;  // ?????????
    bool m_bMouseTranslate;  // ?????
    QPoint m_lastMousePos;  // ???????????�????
    qreal m_scale;  // ?????
};

#endif // INTERACTIVE_VIEW_H
