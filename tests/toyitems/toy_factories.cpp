// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "toy_factories.h"
#include "sessionitem.h"
#include "toy_constants.h"
#include "toy_items.h"
#include <stdexcept>

using namespace ToyItems;

ModelView::SessionItem* ItemFactory::createItem(const ModelView::model_type& modelType)
{
    ModelView::SessionItem* result(nullptr);

    if (modelType == Constants::MultiLayerType)
        result = new MultiLayer;

    else if (modelType == Constants::LayerType)
        result = new Layer;

    if (!result)
        throw std::runtime_error("ItemFactory::createItem() -> Error. Unknown model '"+
                                 modelType+"'");

    result->setDisplayName(modelType);
    return result;
}

ModelView::SessionItem* ItemFactory::createEmptyItem()
{
    return new ModelView::SessionItem;
}