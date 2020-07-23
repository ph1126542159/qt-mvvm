// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef MVVM_SIGNALS_ITEMMAPPER_H
#define MVVM_SIGNALS_ITEMMAPPER_H

#include <memory>
#include <mvvm/signals/modellistener.h>

namespace ModelView
{

class SessionItem;
class SessionModel;

//! Provides notifications on various changes for a specific item.
//! ItemMapper listens signals coming from the model (i.e. via ModelMapper) and processes only whose
//! signals which are related to the given item. Notifies all interested subscribers about things
//! going with the item and its relatives.

class MVVM_MODEL_EXPORT ItemMapper : ModelListener<SessionModel>
{
public:
    ItemMapper(SessionItem* item);
    ~ItemMapper();

    void setOnItemDestroy(Callbacks::item_t f, Callbacks::slot_t owner);
    void setOnDataChange(Callbacks::item_int_t f, Callbacks::slot_t owner);
    void setOnPropertyChange(Callbacks::item_str_t f, Callbacks::slot_t owner);
    void setOnChildPropertyChange(Callbacks::item_str_t f, Callbacks::slot_t owner);
    void setOnItemInserted(Callbacks::item_tagrow_t f, Callbacks::slot_t owner);
    void setOnItemRemoved(Callbacks::item_tagrow_t f, Callbacks::slot_t owner);
    void setOnAboutToRemoveItem(Callbacks::item_tagrow_t f, Callbacks::slot_t owner);

    void setActive(bool value);

    void unsubscribe(Callbacks::slot_t client);

private:
    friend class SessionItem;

    void unsubscribe_from_model();

    void callOnItemDestroy();

    struct ItemMapperImpl;
    std::unique_ptr<ItemMapperImpl> p_impl;
};

} // namespace ModelView

#endif // MVVM_SIGNALS_ITEMMAPPER_H
