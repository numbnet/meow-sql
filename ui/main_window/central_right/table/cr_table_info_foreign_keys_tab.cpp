#include "cr_table_info_foreign_keys_tab.h"
#include "cr_table_foreign_keys_tools.h"
#include "models/forms/table_info_form.h"
#include "models/forms/table_foreign_keys_model.h"
#include "app.h"

namespace meow {
namespace ui {
namespace main_window {
namespace central_right {
namespace table_info {

ForeignKeysTab::ForeignKeysTab(models::forms::TableInfoForm * form,
                               QWidget *parent)
    : QWidget(parent),
      _tableForm(form)
{
    Q_CHECK_PTR(form);
    createWidgets();
    validateControls();
}

void ForeignKeysTab::createWidgets()
{
    // TODO: show a message when db doesn't support FK

    _mainLayout = new QHBoxLayout();
    _mainLayout->setContentsMargins(4, 4, 4, 4);
    this->setLayout(_mainLayout);

    _tools = new TableForeignKeysTools(this);
    _mainLayout->addWidget(_tools, 0);

    _fKeysTable = new QTableView();
    _fKeysTable->verticalHeader()->hide();
     auto geometrySettings = meow::app()->settings()->geometrySettings();
    _fKeysTable->verticalHeader()->setDefaultSectionSize(
        geometrySettings->tableViewDefaultRowHeight());
    _fKeysTable->horizontalHeader()->setHighlightSections(false);


    auto model = _tableForm->foreignKeysModel();
    _fKeysTable->setModel(model);
    for (int i = 0; i < model->columnCount(); ++i) {
        _fKeysTable->setColumnWidth(i, model->columnWidth(i));
    }

    _fKeysTable->setSelectionBehavior(
          QAbstractItemView::SelectionBehavior::SelectRows);
    _fKeysTable->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(_fKeysTable->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            this,
            &ForeignKeysTab::currentKeyChanged
    );

    _mainLayout->addWidget(_fKeysTable, 1);
}

void ForeignKeysTab::refreshData()
{
    validateControls();
}

void ForeignKeysTab::validateControls()
{
    models::forms::TableForeignKeysModel * model = _tableForm->foreignKeysModel();

    using ColAction = TableForeignKeysTools::Action;

    QModelIndex curIndex = _fKeysTable->selectionModel()->currentIndex();

    _tools->setActionEnabled(ColAction::Add,    model->canAddKey());
    _tools->setActionEnabled(ColAction::Clear,  model->canRemoveAllKeys());
    _tools->setActionEnabled(ColAction::Remove, model->canRemoveKey(curIndex));

}

void ForeignKeysTab::actionAddKey(bool checked)
{
    Q_UNUSED(checked);
}

void ForeignKeysTab::actionRemoveKey(bool checked)
{
    Q_UNUSED(checked);
}

void ForeignKeysTab::actionClearKeys(bool checked)
{
    Q_UNUSED(checked);
}

void ForeignKeysTab::currentKeyChanged(
        const QModelIndex &current,
        const QModelIndex &previous)
{
    Q_UNUSED(current);
    Q_UNUSED(previous);

    validateControls();
}

} // namespace table_info
} // namespace central_right
} // namespace main_window
} // namespace ui
} // namespace meow
