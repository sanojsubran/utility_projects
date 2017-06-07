#pragma once

#include <QObject>
#include <QMainWindow>
#include <QItemDelegate>
#include <QSet>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};


class ComboDelegate : public QItemDelegate
{
   Q_OBJECT
    // QAbstractItemDelegate interface
public:
    ComboDelegate( QObject *parent = nullptr );

    virtual ~ComboDelegate();

    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

private:
    QSet<int> m_items;
};
