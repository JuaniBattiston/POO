#include "labelbutton.h"
#include "ui_labelbutton.h"

LabelButton::LabelButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LabelButton)
{
    ui->setupUi(this);
}

LabelButton::~LabelButton()
{
    delete ui;
}

void LabelButton::setText(QString text)
{
    ui->label->setText(text);
}

void LabelButton::mousePressEvent(QMouseEvent *event)
{
    emit signal_clic();
}
