#include <QComboBox>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel( 4, 4 );
    ui->tableView->setModel( model );

    ComboDelegate *delegate = new ComboDelegate( this );
    ui->tableView->setItemDelegate( delegate );

    for( int row = 0; row < 4; ++row ) {
        for( int column = 0; column < 4; ++column ) {
            QModelIndex index = model->index( row, column, QModelIndex() );
            model->setData( index, QVariant( ( row + 1 ) * ( column + 1) ) );
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

ComboDelegate::ComboDelegate( QObject *parent )
    : QItemDelegate( parent )
{
    for( int i = 0; i < 100; ++i ) {
        m_items.insert( i );
    }
}

ComboDelegate::~ComboDelegate()
{

}

QWidget *ComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *combo = new QComboBox( parent );
    for( int i = 0; i < m_items.count(); ++i ) {
        combo->addItem( QString::number( i ) );
    }
    return combo;
}

void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int val = index.model()->data( index, Qt::EditRole ).toInt();
    QComboBox *combo = static_cast< QComboBox* >( editor );
    QSet<int>::const_iterator iter = m_items.find( val );
    combo->setCurrentIndex( *iter );
}

void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *combo = static_cast< QComboBox* >( editor );
    int val = combo->currentText().toInt();
    qDebug() << val;
    model->setData( index, val, Qt::EditRole );
}
