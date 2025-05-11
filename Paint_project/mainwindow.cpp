#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>  // Для прокрутки
#include "settings.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &MainWindow::animateFigures);

    settingsPanelLayout = new QVBoxLayout();
    settingsPanelLayout->setAlignment(Qt::AlignTop);

    QWidget* settingsWidget = new QWidget(this);
    settingsWidget->setLayout(settingsPanelLayout);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(settingsWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("QScrollArea {"
                              "background-color: #2c2c2c; "
                              "border: none; "
                              "border-radius: 8px; "
                              "} "
                              "QScrollArea QWidget {"
                              "background-color: #3c3c3c; "
                              "border-radius: 8px; "
                              "color: white; "
                              "padding: 10px; "
                              "}");

    ui->settingsPanel->addWidget(scrollArea);

    QFont font("Arial", 11);
    font.setWeight(QFont::Normal);
    QApplication::setFont(font);

    drawWidget = new DrawWidget(this);
    ui->verticalLayout->addWidget(drawWidget);
    drawWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    drawWidget->setStyleSheet("background-color: #000000; border: 1px solid #ccc;");

    statusBar()->show();
    statusBar()->showMessage("Готово к рисованию!");

    QApplication::setStyle("Fusion");
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(0, 0, 0));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(50, 50, 50));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(30, 30, 30));
    darkPalette.setColor(QPalette::AlternateBase, QColor(50, 50, 50));
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Highlight, QColor(255, 215, 0));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    QApplication::setPalette(darkPalette);

    QToolBar* toolBar = addToolBar("Main Toolbar");
    toolBar->setMovable(false);
    toolBar->setStyleSheet("QToolBar {"
                           "background-color: #2c2c2c; "
                           "border: none; "
                           "font-family: 'Arial'; "
                           "font-size: 11px; "
                           "color: white; "
                           "spacing: 8px; "
                           "} "
                           "QToolBar QToolButton {"
                           "background-color: #444444; "
                           "border: none; "
                           "color: white; "
                           "min-width: 40px; "
                           "min-height: 20px; "
                           "border-radius: 4px; "
                           "padding: 6px; "
                           "font-size: 10px; "
                           "} "
                           "QToolBar QToolButton:hover {"
                           "background-color: #555555; "
                           "} "
                           "QToolBar QToolButton:pressed {"
                           "background-color: #FFD700; "
                           "color: black; "
                           "}");

    toolBar->setIconSize(QSize(40, 40));

    QAction* lineAction = toolBar->addAction("Линия");
    QAction* freeLineAction = toolBar->addAction("Ломаная");
    QAction* rectangleAction = toolBar->addAction("Прямоугольник");
    QAction* circleAction = toolBar->addAction("Круг");

    connect(lineAction, &QAction::triggered, this, [this]() {
        currentFigure = FigureType::Line;
        statusBar()->showMessage("Выбрана фигура: Линия");
        drawWidget->setCurrentFigureType(currentFigure);
    });

    connect(freeLineAction, &QAction::triggered, this, [this]() {
        currentFigure = FigureType::FreeLine;
        statusBar()->showMessage("Выбрана фигура: Ломаная");
        drawWidget->setCurrentFigureType(currentFigure);
    });

    connect(rectangleAction, &QAction::triggered, this, [this]() {
        currentFigure = FigureType::Rectangle;
        statusBar()->showMessage("Выбрана фигура: Прямоугольник");
        drawWidget->setCurrentFigureType(currentFigure);
    });

    connect(circleAction, &QAction::triggered, this, [this]() {
        currentFigure = FigureType::Circle;
        statusBar()->showMessage("Выбрана фигура: Круг");
        drawWidget->setCurrentFigureType(currentFigure);
    });

    toolBar->addSeparator();

    QAction* chooseColorAction = toolBar->addAction("Цвет");
    connect(chooseColorAction, &QAction::triggered, this, [this]() {
        QColor color = QColorDialog::getColor(currentColor, this, "Выберите цвет");
        if (color.isValid()) {
            currentColor = color;
            drawWidget->setCurrentColor(currentColor);
        }
    });

    QAction* settingsAction = toolBar->addAction("Толщина");
    connect(settingsAction, &QAction::triggered, this, &MainWindow::openThicknessDialog);

    toggleAnimationAction = toolBar->addAction("Запустить анимацию");
    connect(toggleAnimationAction, &QAction::triggered, this, &MainWindow::toggleAnimation);

    QAction* clearAction = toolBar->addAction("Очистить");
    connect(clearAction, &QAction::triggered, drawWidget, &DrawWidget::clearCanvas);
    connect(clearAction, &QAction::triggered, this, &MainWindow::clearSettingsPanels);

    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacer);

    QAction* loadAction = toolBar->addAction("Загрузить");
    connect(loadAction, &QAction::triggered, this, &MainWindow::loadFromFile);

    QAction* saveAction = toolBar->addAction("Сохранить");
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveToFile);

    connect(drawWidget, &DrawWidget::figureAdded, this, &MainWindow::onFigureAdded);

    QLabel* figuresLabel = new QLabel("Фигуры", this);
    figuresLabel->setAlignment(Qt::AlignCenter);
    settingsPanelLayout->addWidget(figuresLabel);

    connect(drawWidget, &DrawWidget::figure_Selected, this, &MainWindow::onFigureSelected);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveToFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить изображение", "", "PNG (*.png);;JPEG (*.jpg)");
    if (!fileName.isEmpty()) {
        drawWidget->saveImage(fileName);
    }
}

void MainWindow::loadFromFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Загрузить изображение", "", "Images (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {

        figures.clear();
        freeLinePoints.clear();
        tempLine = nullptr;
        tempRectangle = nullptr;
        tempCircle = nullptr;


        backgroundImage.load(fileName);

        drawWidget->setData(figures, currentFigure, tempLine, tempRectangle, tempCircle,
                            freeLinePoints, currentColor, backgroundImage);

        clearSettingsPanels();
        drawWidget->update();
    }
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    drawWidget->setGeometry(0, 0, event->size().width(), event->size().height());
}

void MainWindow::openThicknessDialog() {
    bool ok;
    int thickness = QInputDialog::getInt(this, tr("Выбор толщины линии"),
                                         tr("Толщина линии:"), 2, 1, 50, 1, &ok);
    if (ok) {
        setLineThickness(thickness);
    }
}

void MainWindow::setLineThickness(int thickness) {
    drawWidget->setLineThickness(thickness);
}

void MainWindow::onFigureSelected(Figure* selectedFigure) {
    QLayoutItem* item;
    while ((item = settingsPanelLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->setParent(nullptr);
            delete item->widget();
        }
        delete item;
    }

    if (selectedFigure) {

        QLabel* figuresLabel = new QLabel("Выбранная фигура", this);
        figuresLabel->setAlignment(Qt::AlignCenter);
        settingsPanelLayout->addWidget(figuresLabel);


        Settings* panel = new Settings(selectedFigure);
        panel->setFixedHeight(150);

        connect(panel, &Settings::figureUpdated, this, &MainWindow::onFigureUpdated);
        connect(panel, &Settings::figureDeleted, drawWidget, &DrawWidget::deleteFigure);
        connect(panel, &Settings::figureDeleted, this, [=]() {
            figures.removeOne(selectedFigure);
        });



        settingsPanelLayout->addWidget(panel);
    } else {

        QLabel* figuresLabel = new QLabel("Фигуры", this);
        figuresLabel->setAlignment(Qt::AlignCenter);
        settingsPanelLayout->addWidget(figuresLabel);

        for (Figure* figure : figures) {

            Settings* panel = new Settings(figure);
            panel->setFixedHeight(150);

            connect(panel, &Settings::figureUpdated, this, &MainWindow::onFigureUpdated);
            connect(panel, &Settings::figureDeleted, this, [=]() {
                figures.removeOne(figure);
                drawWidget->deleteFigure(figure);
            });


            settingsPanelLayout->addWidget(panel);
        }
    }
    settingsPanelLayout->update();
}


void MainWindow::onFigureAdded(Figure* figure) {
    if (figure == nullptr) return;

    figures.append(figure);


    Settings* panel = new Settings(figure);
    panel->setFixedHeight(150);

    connect(panel, &Settings::figureUpdated, this, &MainWindow::onFigureUpdated);
    connect(panel, &Settings::figureDeleted, this, [=]() {
        figures.removeOne(figure);
        drawWidget->deleteFigure(figure);
    });


    settingsPanelLayout->addWidget(panel);
}


void MainWindow::clearSettingsPanels() {
    figures.clear();
    QLayoutItem* item;
    while ((item = settingsPanelLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->setParent(nullptr);
            delete item->widget();
        }
    }


    QLabel* figuresLabel = new QLabel("Фигуры", this);
    figuresLabel->setAlignment(Qt::AlignCenter);
    settingsPanelLayout->addWidget(figuresLabel);
}



void MainWindow::toggleAnimation() {

    animationRunning = !animationRunning;

    if (animationRunning) {
        animationTimer->start(30);
        statusBar()->showMessage("Анимация запущена");
        toggleAnimationAction->setText("Остановить анимацию");
    } else {
        animationTimer->stop();
        statusBar()->showMessage("Анимация остановлена");
        toggleAnimationAction->setText("Запустить анимацию");
    }
}


void MainWindow::animateFigures()
{
    if (!figures.isEmpty())
    {
        for (Figure* figure : figures) {
            figure->animate(drawWidget->size());
        }
        update();
    }
}
