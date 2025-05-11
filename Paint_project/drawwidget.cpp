#include "drawwidget.h"
#include "mainwindow.h"
#include "ui_drawwidget.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

DrawWidget::DrawWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DrawWidget)
{
    ui->setupUi(this);
    setStyleSheet("background-color: white;");
    previousSize = size();
    lineThickness = 2;
}

DrawWidget::~DrawWidget()
{
    delete ui;
    qDeleteAll(figures);
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    if (!backgroundImage.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), backgroundImage);
    }

    for (Figure* figure : figures) {
        if (figure == selectedFigure) continue;
        painter.setPen(QPen(figure->getColor(), figure->getLineThickness()));
        figure->draw(&painter);
    }

    if (selectedFigure) {
        QPen selectedPen(Qt::red, selectedFigure->getLineThickness() + 2, Qt::DashLine);
        bool ex = 1;
        painter.setPen(selectedPen);
        selectedFigure->draw(&painter, ex);
    }

    if (currentFigure == FigureType::FreeLine && !freeLinePoints.isEmpty() && !selectedFigure) {
        QPen pen(currentColor, lineThickness);
        painter.setPen(pen);
        for (int i = 1; i < freeLinePoints.size(); ++i) {
            painter.drawLine(freeLinePoints[i - 1], freeLinePoints[i]);
        }
    }

    if (currentFigure == FigureType::Line && tempLine && !selectedFigure) {
        QPen pen(tempLine->color, tempLine->getLineThickness());
        painter.setPen(pen);
        painter.drawLine(tempLine->first, tempLine->last);
    }

    if (currentFigure == FigureType::Rectangle && tempRectangle && !selectedFigure) {
        tempRectangle->draw(&painter);
    }

    if (currentFigure == FigureType::Circle && tempCircle && !selectedFigure) {
        tempCircle->draw(&painter);
    }
}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    QPointF pos = event->pos();
    bool figureSelected = false;

    for (Figure* figure : figures) {
        if (figure->contains(pos)) {
            selectedFigure = figure;
            figureSelected = true;
            emit figure_Selected(figure);
            break;
        }
    }

    if (!figureSelected) {
        selectedFigure = nullptr;
        emit figure_Selected(nullptr);
    }

    if (event->button() == Qt::LeftButton && !selectedFigure) {
        if (currentFigure == FigureType::FreeLine) {
            freeLinePoints.clear();
            freeLinePoints.append(pos);
        } else if (currentFigure == FigureType::Line) {
            tempLine = new Line(pos, pos, currentColor, lineThickness);
        } else if (currentFigure == FigureType::Rectangle) {
            rectStartPoint = pos;
            tempRectangle = new Rectangle(pos, pos, currentColor, lineThickness);
        } else if (currentFigure == FigureType::Circle) {
            rectStartPoint = pos;
            tempCircle = new Circle(pos, 0, currentColor, lineThickness);
        }
    }

    update();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (currentFigure == FigureType::FreeLine && !selectedFigure) {
        QPointF newPos = event->pos();
        if (freeLinePoints.last() != newPos) {
            freeLinePoints.append(newPos);
            update();
        }
    } else if (currentFigure == FigureType::Line && tempLine && !selectedFigure) {
        tempLine->last = event->pos();
        update();
    } else if (currentFigure == FigureType::Rectangle && tempRectangle && !selectedFigure) {
        delete tempRectangle;
        tempRectangle = new Rectangle(rectStartPoint, event->pos(), currentColor, lineThickness);
        update();
    } else if (currentFigure == FigureType::Circle && tempCircle && !selectedFigure) {
        qreal radius = QLineF(rectStartPoint, event->pos()).length();
        tempCircle->setRadius(radius);
        update();
    }
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !selectedFigure &&
        (freeLinePoints.size() != 0 || tempLine || tempRectangle || tempCircle)) {

        if (currentFigure == FigureType::FreeLine) {
            if (freeLinePoints.size() >= 2) {
                Figure* newFigure = new FreeLine(freeLinePoints, currentColor, lineThickness);
                figures.append(newFigure);
                emit figureAdded(newFigure);
            }
            freeLinePoints.clear();
        } else if (currentFigure == FigureType::Line) {
            if (tempLine && tempLine->first != tempLine->last) {
                tempLine->last = event->pos();
                figures.append(tempLine);
                emit figureAdded(tempLine);
            } else {
                delete tempLine;
            }
            tempLine = nullptr;
        } else if (currentFigure == FigureType::Rectangle) {
            if (tempRectangle && tempRectangle->getWidth() > 1 && tempRectangle->getHeight() > 1) {
                figures.append(tempRectangle);
                emit figureAdded(tempRectangle);
            } else {
                delete tempRectangle;
            }
            tempRectangle = nullptr;
        } else if (currentFigure == FigureType::Circle) {
            if (tempCircle && tempCircle->getRadius() > 1) {
                figures.append(tempCircle);
                emit figureAdded(tempCircle);
            } else {
                delete tempCircle;
            }
            tempCircle = nullptr;
        }
    }

    update();
}

void DrawWidget::setCurrentColor(const QColor &color)
{
    currentColor = color;
}

void DrawWidget::setCurrentFigureType(FigureType type)
{
    currentFigure = type;
}

void DrawWidget::resizeEvent(QResizeEvent* event)
{
    if (!previousSize.isEmpty()) {
        qreal scaleX = (qreal)event->size().width() / previousSize.width();
        qreal scaleY = (qreal)event->size().height() / previousSize.height();

        for (Figure* figure : figures) {
            figure->scale(scaleX, scaleY);
        }
    }

    previousSize = event->size();
    update();
}

QList<Figure*> DrawWidget::getFigures()
{
    return figures;
}

void DrawWidget::deleteFigure(Figure* figure)
{
    int index = figures.indexOf(figure);
    if (index != -1) {
        if (figure == selectedFigure) selectedFigure = nullptr;
        figures.removeAt(index);
        delete figure;
    }

    update();
}

void DrawWidget::clearCanvas()
{
    qDeleteAll(figures);
    figures.clear();
    freeLinePoints.clear();
    tempLine = nullptr;
    tempRectangle = nullptr;
    tempCircle = nullptr;
    backgroundImage = QPixmap();
    selectedFigure = nullptr;
    emit canvasCleared();
    update();
}

void DrawWidget::saveImage(const QString& filePath)
{
    QPixmap pixmap(size());
    QPainter painter(&pixmap);
    render(&painter);
    pixmap.save(filePath);
}

void DrawWidget::setData(QList<Figure*>& newFigures,
                         FigureType type,
                         Line* line,
                         Rectangle* rect,
                         Circle* circle,
                         QVector<QPointF> points,
                         QColor color,
                         QPixmap image)
{
    qDeleteAll(figures);
    figures = newFigures;
    currentFigure = type;
    tempLine = line;
    tempRectangle = rect;
    tempCircle = circle;
    freeLinePoints = points;
    currentColor = color;
    backgroundImage = image;
    selectedFigure = nullptr;
    update();
}
