// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "global.h"
#include <QStandardItemModel>

class QStandardItem;

namespace ModelView
{

class SessionModel;
class SessionItem;
class ViewItem;

//! Base class for all view models to show content of  SessionModel in Qt views.

class CORE_EXPORT ViewModel : public QStandardItemModel
{
public:
    ViewModel(QObject* parent = nullptr);
    virtual ~ViewModel();

    void setSessionModel(SessionModel* model);

    std::vector<ViewItem*> findViews(const SessionItem* item) const;

    const SessionItem* sessionItemFromIndex(const QModelIndex &index) const;

    QModelIndexList indexOfSessionItem(const SessionItem* item);

    void setRootSessionItem(const SessionItem* item);

protected:
    const SessionItem* rootSessionItem() const;
    QStandardItem* rootStandardItem();

    std::vector<QStandardItem*> findStandardViews(const SessionItem* item);

protected:
    virtual void init_view_model() = 0;
    virtual void onDataChange(SessionItem* item, int role);
    virtual void onRowInserted(SessionItem* parent, std::string tag, int row);
    virtual void onRowRemoved(SessionItem* parent, std::string tag, int row);

    SessionModel* m_sessionModel;
    const SessionItem* m_rootItem;
};

} // namespace ModelView

#endif // VIEWMODEL_H
