#include "number_generator.h"
#include "qfiledialog.h"
#include "qstring.h"
#include "qvariant.h"
#include "qtimer.h"
#include <QTime>
#include <Windows.h>
#pragma execution_character_set("utf-8")

static QString head_string =  "´¨AF";

static QVariant CastQString2QVarint(const QVector<QString>& data)
{
    QList<QVariant> table;
    for (int i = 0; i < data.size(); ++i) {
        QList<QVariant> row_variant;
        row_variant.append(QVariant(data[i]));
        table.append(QVariant(row_variant));
    }
    return table;
}

NumberGenerator* NumberGenerator::m_instance(nullptr);

static int GetRandNumber() 
{
    int start_num, end_num;
    start_num = 9999;
    end_num = 99999;
    qsrand(QTime(0, 0, 0).msecsTo(QTime::currentTime()));
    int rand_num = start_num + qrand() % (end_num -start_num);
    return rand_num;
}


NumberGenerator::NumberGenerator()
{
}

NumberGenerator::~NumberGenerator()
{
    Destory();
}

void NumberGenerator::Destory()
{
    if (m_instance) {
        delete m_instance;
        m_instance = nullptr;
    }
}

void NumberGenerator::GenrateNumberExcel()
{
    OpenFile();
    QVector<QString> data =  GenerateNumber();
    WriteDataInFile(data);
    CloseFile();
}

NumberGenerator* NumberGenerator::Instane()
{
    if (m_instance == nullptr) {
        m_instance = new NumberGenerator();
    }

    return m_instance;
}

QVector<QString> NumberGenerator::GenerateNumber()
{
    QVector<QString> vector_string;

    int start_num, end_num;
    start_num = 9999;
    end_num = 99999;
    qsrand(QTime(0, 0, 0).msecsTo(QTime::currentTime()));


    for (int i = 0 ; i < 1000; ++i) {
        QString car_number  = head_string;
        int rand_num = start_num + qrand() % (end_num - start_num);
        car_number += QString::number(rand_num);
        vector_string.append(car_number);
    }

    return vector_string;

}

void NumberGenerator::OpenFile()
{
    m_excel = new QAxObject("Excel.Application");
    m_excel->dynamicCall("SetVisible (bool visible)", "false");
    m_excel->setProperty("DisplayAlerts", false);

    QAxObject* workbooks = m_excel->querySubObject("Workbooks");
    workbooks->dynamicCall("Add");
    m_workbook = m_excel->querySubObject("ActiveWorkBook");

    QAxObject* sheet = m_workbook->querySubObject("Worksheets");
    m_sheet = sheet->querySubObject("Item(int)", 1);
   
}

void NumberGenerator::CloseFile()
{
    QString file_name = QFileDialog::getSaveFileName(NULL, tr("get exel file name"), "", "files (*.xlsx)");
    m_workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(file_name));
    m_workbook->dynamicCall("Close()");
    m_excel->dynamicCall("Quit()");
    
}

void NumberGenerator::WriteDataInFile(const QVector<QString>& data)
{
    QString Range = "A1:A" + QString::number(data.size());
    QVariant table = CastQString2QVarint(data);
    QAxObject* range_cell = m_sheet->querySubObject("Range(const QVariant&)", Range);
    range_cell->dynamicCall("SetValue(const QVariant)", table);
}
