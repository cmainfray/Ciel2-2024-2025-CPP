#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
    ,NB_TOUCHES(16)
{
    ui->setupUi(this);
    const QString tableDesSymboles[ ] = {"7", "8", "9", "+" ,"4", "5", "6", "-", "1", "2", "3", "*",
                                        "C", "0", "=", "/"};
    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("font-size: 25px ; background-color: rgb(143, 240, 164); ");
    afficheur->setAlignment(Qt::AlignRight);
    afficheur->setReadOnly(true);
    touches = new QPushButton*[NB_TOUCHES];
    grille->addWidget(afficheur,0,0,1,4);
    this->setLayout(grille);
    for(int indice = 0 ; indice < NB_TOUCHES; indice++){
        touches[indice] = new QPushButton;
        touches[indice] -> setText(tableDesSymboles[indice]);
        touches[indice] -> setMinimumSize(QSize(50,50));
        grille -> addWidget(touches[indice],indice/4+1,indice%4);
        connect(touches[indice], &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    }

}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString val;
    val=touche->text();
    if(val == "=" ){
        QJSEngine expression;
        afficheur->setText(expression.evaluate(afficheur->text()).toString());
    }
    else if(val == "C")
        afficheur -> clear();
    else {
        afficheur->setText(afficheur->text()+ val);
    }
}
