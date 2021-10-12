#include "main_widget.h"
#include "qpushbutton.h"
#include "qlayout.h"

MainWidget::MainWidget()
{
    this->setFixedSize(QSize(200, 50));
    SetUi();
}

MainWidget::~MainWidget()
{
}

void MainWidget::SetUi()
{
    QPushButton* import_button = new QPushButton(tr("Import"));
    QPushButton* output_button = new QPushButton(tr("Output"));
    QPushButton* generate_button = new QPushButton(tr("Generate"));

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(generate_button);
    layout->addWidget(import_button);
    layout->addWidget(output_button);

    this->setLayout(layout);
}

void MainWidget::ImportExcel()
{
}

void MainWidget::OutPutExcel()
{
}

void MainWidget::GenerateExcel()
{

}