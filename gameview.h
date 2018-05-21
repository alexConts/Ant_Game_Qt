#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QMainWindow>
#include "game.h"
#include "item.h"
#include <QList>
#include <QGraphicsScene>

class Game;
class GameModel;

namespace Ui {
class GameView;
}

class GameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = 0);
    ~GameView();
    void setControl(Game *control) {
        this->control = control;
    }
    void update(QList<Item*> data);
    void test();
    void add_item(Item * item);

private slots:
    void on_harvesterCreate_clicked();

private:
    Ui::GameView *ui;
    QGraphicsScene * scene;
    Game *control;
};

#endif // GAMEVIEW_H
