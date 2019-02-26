#ifndef MOCKWIDGETS_H
#define MOCKWIDGETS_H

#include "MockInterfaces.h"
#include <gmock/gmock.h>

namespace ModelView {
class SessionItem;
class SessionModel;
}


//! Mock class for CallbackContainer.

class CallbackMockWidget
{
public:
    MOCK_METHOD1(onItemDestroy, void(ModelView::SessionItem* item));
    MOCK_METHOD2(onDataChange, void(ModelView::SessionItem* item, int role));
};

//! Mock widget to test ItemMapper functionality.

class MockWidgetForItem : public ItemTestWidgetInterface {
public:
    MockWidgetForItem(ModelView::SessionItem* item);
    ~MockWidgetForItem();

    void setItem(ModelView::SessionItem* item);

    MOCK_METHOD1(onItemDestroy, void(ModelView::SessionItem* item));
    MOCK_METHOD2(onDataChange, void(ModelView::SessionItem* item, int role));
    MOCK_METHOD2(onPropertyChange, void(ModelView::SessionItem* item, std::string name));

private:
    ModelView::SessionItem* m_item;
};

//! Mock class to test ModelMapper functionality.

class MockWidgetForModel : public ModelTestWidgetInterface {
public:
    MockWidgetForModel(ModelView::SessionModel* item);
    ~MockWidgetForModel();

    void setModel(ModelView::SessionModel* model);

    MOCK_METHOD2(onDataChange, void(ModelView::SessionItem* item, int role));
    MOCK_METHOD2(onRowInserted, void(ModelView::SessionItem* item, int row));
    MOCK_METHOD2(onRowRemoved, void(ModelView::SessionItem* item, int row));

private:
    ModelView::SessionModel* m_model;
};

#endif //  MOCKWIDGETS_H
