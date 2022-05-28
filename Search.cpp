#include "Search.h"

Search::Search(QWidget* parent, const QString& tempFileName) : QMainWindow(parent),
m_ui(new Ui::SearchClass), m_tempFileName(tempFileName) {
    m_ui->setupUi(this);
}

Search::~Search() {
    delete m_ui;
}

void Search::closeEvent(QCloseEvent* event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, this->accessibleName(),
        tr("Are you sure?\n"),
        QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
        QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes) event->ignore();

    else {
        QFile file(m_tempFileName);

        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }

        file.remove();
        event->accept();
    }
}

void Search::on_search_clicked() {
    QString word = m_ui->textEdit->toPlainText();

    QFile file(m_tempFileName);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    QTextStream in(&file);
    QString line;

    if (in.atEnd()) {
        m_ui->textBrowser->setTextColor("red");
        m_ui->textBrowser->setText("NO TEXT FOUND >:(");
        return;
    }

    if (word.isEmpty()) return;

    int lineNumber = 1;
    m_ui->textBrowser->setTextColor("white");
    m_ui->textBrowser->setText(word + " exists at lines: ");
    bool found = false;
    while (!in.atEnd()) {
        line = in.readLine();
        if (line.contains(word)) {
            m_ui->textBrowser->append(QString::number(lineNumber));
            found = true;
        }
        lineNumber++;
    }
    if (!found) {
        m_ui->textBrowser->setTextColor("blue");
        m_ui->textBrowser->setText(word + " doesn't exist :(");
    }
}
